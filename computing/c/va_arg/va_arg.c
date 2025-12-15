
#include <stdarg.h>
#include <stdio.h>

void print_nums(int first_arg, ...)
{
  va_list args;
  va_start(args, first_arg);

  printf("First argument: %d\n", first_arg);

  int num;
  while ((num = va_arg(args, int)) != 0)
  {
    printf("Next argument: %d\n", num);
  }

  va_end(args);
}

int main()
{
  print_nums(1, 2, 3, 4, 0); // Example usage
  return 0;
}
