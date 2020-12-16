#include "stack.h"

#define STACK_SIZE 5

//Backing store
int StackStore [STACK_SIZE];

//Pointer to top of stack elementfor adding and retrieving (will always be top element in a LIFO stack)
int* topStackPtr;

//Initialize the stack
void stack_init(void)
{
  topStackPtr = 0;
  
  for(int i=0; i<STACK_SIZE; i++)
  {
    StackStore[i] = 0;
  }
}



//Get data from the stack
//If stack is empty return error
//Otherwise return success

int stack_pop(int* data)
{
  if (topStackPtr == 0)
  {
    //stack is empty
    return -1;
  }
  *data = *topStackPtr;
  
  if (topStackPtr == &StackStore[0])
  {
    topStackPtr = 0;
  }
  
  else
  {
    topStackPtr--;
  }
  return 0;
}


//Push data to the stack
//If stack is full return error
//Otherwise return success

int stack_push (int data)
{
  if (topStackPtr == &StackStore[STACK_SIZE])
  {
    //stack is full
    return 1;
  }
  
  if (topStackPtr == 0)
  {
      topStackPtr = &StackStore[0];
  }
  else
  {
    topStackPtr++;
  }
  
  return 0;
}