
// expected output 
// Hello, World!
// t1 0 t2 2 
// t1 0 t2 2 

#include <stdio.h>

struct test {
char i ;
char j ;

};

int main()
{
    printf("Hello, World!\n");

    struct test t1 = {0,1} ;

    struct test t2[2] = {{0,1} , {2,3}};

    printf("t1 %d t2 %d \n", t1.i , t2[1].i);
    
    struct test * ptr[2];
    
    ptr [0] = &t1;
    ptr [1] = &t2;
    
    printf("t1 %d t2 %d \n", ptr[0]->i , ptr[1][1].i);
    
    
    return 0;
}
