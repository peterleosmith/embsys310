#include "swap.h"

void pointerSwap (int *ptra, int *ptrb)
{
  int temp =*ptra;
  *ptra = *ptrb;
  *ptrb = temp;
}