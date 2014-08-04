#include <stdio.h>
#include <stdlib.h>

#define COUNT 500000000

int main()
{
  printf("Hello World\n");
  int x=0;
  for( int i=0; i<COUNT; i++)
  {
    x=x+i;
  }
  printf("%i\n",x);
  return EXIT_SUCCESS;
}
