
#include <stdlib.h>
#include <string.h>

#include <jansson.h>

#define NUMBER_CARDS (2)

void add_2array_to_json( json_t* obj, const char* name, const int*
marr, size_t dim1, size_t dim2 )
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

int main()
{
    json_t* jdata;
    char* s;
    int arr1[2][3] = { {1,2,3}, {4,5,6} };
    int arr2[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };

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
    free( s );
    json_decref( jdata );

    return 0;
}

