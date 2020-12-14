### Assignment 4

##### 1.Follow the same steps as we did in the class to blink LED1 at a visible rate using the bit-band region to enable the clock to Port A, then answer the following:
######    a. What instructions does the complier produce in assembly for "writing" to the GPIO bi when using the bi-band address?
Assuming this meant when writing to the clock enable register, not the GPIOx_ODR, since bit banding was only used for the clock enable register.  The compiler produced MOVS (move 1 into R0), LDR.N (load the target address into R1), and STR (store the value in R1 into the address of R0)


######    a. What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?
Again, assuming this meant the clock enable register, the 4 instructions produced were LDR.N (load target address into R0), LDR (load value of address into R1), ORRS.W (OR the value of R1 w/ 1 and put the result in R1), & STR (store the result from R1 into the address in R0).


##### 2. Create a function"func1" with 5 arguments and call func1 from within another function "func2". Trace thru the assembler and note:

######  a. How does the calling function "func2" pass the values to the called function func1?
When func1 is called, the 5th argument is moved into R0, and is then stored in the stack. Arguments 4, 3, 2, and 1 are then moved in registers R3 - R0, respectively.

######  b. What extra code did the compiler generate before calling the function "func1" with the multiple arguments?
The compiler pushed the value of the link register to the stack because there is a BL instruction generated with func1 which will modify the LR.

######  c. What extra code did the compiler generate inside the called function "func1" with the multiple list of arguments?
The compiler pushed the values in R4-R8 and LR to the stack and also loaded the 5th argument that had been stored on the stack in func2.

###### d. Any other observations?
In func1, the values of the arguments are moved to registers R6-R8, R12, and LR for the ADD.
