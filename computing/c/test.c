

#include "stdio.h"


void main(void) 
{
    char *fibre="fibre2";
    char *device="fibre2";
    char *hwAddr="78:f9:b4:ce:fa:8b";

    if((strcmp(device, fibre) == 0) && (strcmp(hwAddr, "00:00:00:00:00:00") != 0)) {
        printf("erroe");
    }
    return ;
}
