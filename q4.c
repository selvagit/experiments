

#include <stdio.h>
#include <math.h>

void print_float( float f)
{
    int j = (int)floor(f);
    int k = (int)((f-(float)j)*100);
    
    printf("%d.%d",j,k);
}


int main ( void) 
{
    float f = 10.4567;

    print_float(f);

	return 0;
}    


    




