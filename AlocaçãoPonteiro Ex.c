#include <stdio.h>
#include <stdlib.h>

int main()
{
  float *vet;
  int i;
 
  vet = (float *)malloc(sizeof(float) * 10);
  
  for (i = 0; i < 10; i++) {

     printf("%p\n", (vet + i));
     
  }
  
  return 0;
}