#include <assert.h>
#include "stack.h"


int main()
{
  
  int result1;
  int result2;
  int testInt;
  
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 99;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testInt);
   
  
    // Assert:
    assert(-1 == result1); //
    assert(99 == testInt); 
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the queue
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 3;
    stack_init();
  
    // Act:
    result1 = stack_push(99);
    result2 = stack_pop(&testInt);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(99 == testInt);
    
    // *******************************************************************
    // Test3: Fill queue, then get all items.
    // *******************************************************************
    // Arrange:
    testInt = 99;
    stack_init();
    
    // Act:
    stack_push(21);
    stack_push(22);
    stack_push(23);
    stack_push(24);
    stack_push(25);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(25 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(24 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(23 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(22 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(21 == testInt);

    
    // *******************************************************************
    // Test4: Fill queue, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testInt = 99;
    stack_init();
    
    // Act:
    stack_push(21);
    stack_push(22);
    stack_push(23);
    stack_push(24);
    stack_push(25);
    
    // Assert:
    assert(-1 == stack_push(testInt));
      
  
  return 0;
}
