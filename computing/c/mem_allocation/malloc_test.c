#include <malloc.h>
#include <stdio.h>

int main(void)
{
  int* dptr;
  dptr = malloc(1024 * 1024 * 1024);

  printf(" memory alocate = %x", dptr);

  free(dptr);

  return 0;
}
