#include "stdio.h"
#include "string.h"

// function for macro conversion 
void print_macro(void){
    #define progn(x) { \
    char test [] = __STRING(x); \
    printf("%s\n",test); \
    }
    #include "macro.def"
    #undef progn
}

int  main(void) 
{
    char *fibre="fibre2";
    char *device="fibre2";
    char *hwAddr="78:f9:b4:ce:fa:8b";

    if((strcmp(device, fibre) == 0) && (strcmp(hwAddr, "00:00:00:00:00:00") != 0)) {
        printf("error\n");
    }

    print_macro();

    return 0;
}
