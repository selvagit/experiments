#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/resource.h>

#include <jansson.h>

#define NUMBER_CARDS (2)

void add_2array_to_json( json_t* obj, const char* name, 
		const int* marr, size_t dim1, size_t dim2 )
{
	size_t i, j;
	json_t* jarr1 = json_array();

	for( i=0; i<dim1; ++i ) {
		json_t* jarr2 = json_array();

		for( j=0; j<dim2; ++j ) {
			int val = marr[ i*dim2 + j ];
			json_t* jval = json_integer( val );
			json_array_append_new( jarr2, jval );
		}
		json_array_append_new( jarr1, jarr2 );
	}
	json_object_set_new( obj, name, jarr1 );
	return;
}


/*
 * Measures the current (and peak) resident and virtual memories
 * usage of your linux C process, in kB
 */
void getMemory( int* currRealMem, int* peakRealMem,
		int* currVirtMem, int* peakVirtMem) {

	// stores each word in status file
	char buffer[1024] = "";

	// linux file contains this-process info
	FILE* file = fopen("/proc/self/status", "r");

	if (file != NULL) {
		// read the entire file
		while (fscanf(file, " %1023s", buffer) == 1) {

			if (strcmp(buffer, "VmRSS:") == 0) {
				fscanf(file, " %d", currRealMem);
			}
			if (strcmp(buffer, "VmHWM:") == 0) {
				fscanf(file, " %d", peakRealMem);
			}
			if (strcmp(buffer, "VmSize:") == 0) {
				fscanf(file, " %d", currVirtMem);
			}
			if (strcmp(buffer, "VmPeak:") == 0) {
				fscanf(file, " %d", peakVirtMem);
			}
		}
		fclose(file);
	} else {
		printf ("The file ould not be opened \n");
	}
}

int rs() {
	struct rusage r_usage;
	getrusage(RUSAGE_SELF,&r_usage);
	// Print the maximum resident set size used (in kilobytes).
	printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
	return 0;
}
typedef struct {
	unsigned long size,resident,share,text,lib,data,dt;
} statm_t;

void read_off_memory_status(statm_t *result)
{
	const char* statm_path = "/proc/self/statm";

	FILE *f = fopen(statm_path,"r");
	if(!f){
		perror(statm_path);
		abort();
	}

	if(7 != fscanf(f,"%ld %ld %ld %ld %ld %ld %ld",&result->size, &result->resident, &result->share, 
                &result->text, &result->lib, &result->data, &result->dt)){
		perror(statm_path);
		abort();
	}

	fclose(f);
}

int main()
{
	int currRealMem; int peakRealMem; int currVirtMem; int peakVirtMem;
	statm_t result;

	json_t* jdata;
	char* s;
	int arr1[2][3] = { {1,2,3}, {4,5,6} };
	int arr2[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };

    {
	getMemory(&currRealMem, &peakRealMem, &currVirtMem, &peakVirtMem); 
	printf ("currRealMem = %d peakRealMemi = %d currVirtMem = %d peakVirtMem  = %d \n",
            currRealMem, peakRealMem, currVirtMem, peakVirtMem);
	rs();
    }

	read_off_memory_status(&result);
	printf (" size = %d , resident %d \n", result.size, result.resident);


	jdata = json_object();
	add_2array_to_json( jdata, "arr1", &arr1[0][0], 2, 3 );
	add_2array_to_json( jdata, "arr2", &arr2[0][0], 4, 4 );

	json_object_set_new(jdata, "state", json_string("success")); 

	json_t * jcards = json_array();
	json_object_set_new(jdata, "cards", jcards);

	int card;
	for (card = 0; card < NUMBER_CARDS; card++) {
		json_t * jf = json_object();
		json_array_append_new(jcards, jf);

		json_object_set_new(jf, "fpgaTemp", json_real(1.51));
		json_object_set_new(jf, "systemTemp", json_real(3.5));
	}

	s = json_dumps( jdata, JSON_COMPACT | JSON_INDENT(2) );
	puts( s );

    {
	getMemory(&currRealMem, &peakRealMem, &currVirtMem, &peakVirtMem); 
	printf ("currRealMem = %d peakRealMemi = %d currVirtMem = %d peakVirtMem  = %d \n",
            currRealMem, peakRealMem, currVirtMem, peakVirtMem);
	rs();
    }


	read_off_memory_status(&result);
	printf (" size = %d , resident %d \n", result.size, result.resident);

	free( s );
	json_decref( jdata );

	return 0;
}

