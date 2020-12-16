#include<stdio.h>
#include "swap.h"


int main()
{
  int a = 36;
  int b = 87;
  
  int* ptra = &a;
  int* ptrb = &b;
  
  pointerSwap(ptra, ptrb);
  
  printf("%d", *ptra);
  printf("%d", *ptrb);
  
  
  return 0;
}
