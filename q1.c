/*
Write a short C program which prints out all of the subsets
of the numbers in the range 1..23 which add up to 23.
Subsets should be printed one per line with a single space
between each number. Each subset should be free of duplicates.
   
One of the subsets might look like this:

1 2 4 16
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SET (50)

struct sub_set
{
    int num_of_entry ; 
    int temp_array[MAX_SET];
} ;

int test1(int set_sum, struct sub_set *curr_set);

int sum_of_sub_set( struct sub_set * temp ) 
{   
    int sum = 0;
    int i;
    for ( i = 0 ; i < temp->num_of_entry ; i ++ )
    {
        sum += temp->temp_array[i];
    }

    return sum ;
}

void print_sub_set( struct sub_set * curr, struct sub_set * local ) 
{   
    int i;
    struct sub_set * temp = curr;
    for ( i = 0 ; i < temp->num_of_entry ; i ++ )
    {
        printf ( "%d ", temp->temp_array[i] );
    }
    
    temp = local;
    for ( i = 0 ; i < temp->num_of_entry ; i ++ )
    {
        printf ( "%d ", temp->temp_array[i] );
    }
}


int test1 (int set_sum, struct sub_set *sub_set_current)
{
    int i,j,sum;
    int set_sz = set_sum-1;
    
    struct sub_set sub_set_local ;

    for ( i = set_sz; i > 0; i-- )
    {
        sub_set_local.num_of_entry = 1;
        sub_set_local.temp_array[sub_set_local.num_of_entry-1] = i;

        for ( j = i-1 ; j > 0 ; j--)
        {
            sum = j + sum_of_sub_set(&sub_set_local); 
                
            if( sum <= set_sum )
            {
                sub_set_local.num_of_entry++;
                sub_set_local.temp_array[sub_set_local.num_of_entry-1] = j;

                if( sum == set_sum )
                {
                    print_sub_set(sub_set_current, &sub_set_local);
                    printf ("\n");
                    if( j == 1 || j == 2 )
                    {
                        //printf ("end \n");
                        //printf ("1-ret: i = %d , j = %d\n", i,j);
                        break;
                    }else
                    {    
                        sub_set_local.num_of_entry--;
                        test1(j,&sub_set_local);
                        //printf ("2-ret: i = %d , j = %d\n", i,j);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}


int main(int argc, char *argv[])
{
	if( argc > 1 )
	{
		struct sub_set curr_set;
		memset(&curr_set,0,sizeof(curr_set));

		if( atoi(argv[1]) > 0)
		{
			test1 (atoi(argv[1]),&curr_set);
		}
	}

	return 0;
}
