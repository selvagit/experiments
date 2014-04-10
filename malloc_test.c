#include <stdio.h>
#include <malloc.h>


int main (void)
{
    int *dptr; 
    dptr = malloc(1024*1024*1024);

    printf(" memory alocate = %x", dptr );

    free(dptr);

    return 0;

}
