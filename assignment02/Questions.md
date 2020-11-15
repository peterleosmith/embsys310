Assignment 02
####1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program
only once to increment “counter”.
#####a) What is the value of the “counter” from the “Locals” window?
-2147483648
#####b) What is the value of the “counter” in the “Registers” window?
0x80000000
#####c) Please note down if the N and/or V flags are set in the APSR register. And explain why.
N and V flags are both set because the incrementing the value of the variable caused the most significant bit to be set to one. The N flag reads this bit and indicates that it is a negative number.  The V Flag is set to one since a carry flipped the MSB, which means that the value will go beyond the range that range of numbers that can be represented in 2's complement signed format.

####2) If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program
once to increment “counter”
#####a) What happens to the value of “counter” in the “Locals” window?
0xFFFFFFFF in the Register value displays as -1 in the Locals window.  Stepping thru the code once changes the value to “0” in the Locals window.
#####b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
The N and V flags are not set in the APSR register since the result of the ADD is not negative (most significant bit is zero), and a signed overflow did not occur.

####3) Change the “counter” variable type in your code to “unsigned int”. Inject the values
“0x7FFFFFFF” then step thru the program to increment the “counter” once:
#####a) What is the value of “counter” in the “Locals” window after incrementing for each value?
The value of the variable in the Locals window simply increases from 2147483647 to 2147483648.
#####b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
The N flag is set because the most significant bit of the result is 1.  The V flag is set since a carry flipped the MSB to 1, but the complier disregards this information in the Locals window for unsigned ints.
####4) Change the counter variable in your code to unsigned. Inject the values of “0xFFFFFFFF” then step thru the program to increment the “counter” once:
#####a) What is the value of “counter” in the “Locals” window after incrementing for each value?
The value of the variable in the Locals window goes from 4294967295 to 0.
#####b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
The N flag is not set because the most significant bit is still set to 0.  The V flag is not set since the result of the positive + positive operation is 0 (i.e. not negative).
####5) Move the “counter” variable outside of main (at the top of the file):
#####a) What is the scope of the variable “counter”
Global
#####b) Is it still visible in the Locals view?
No
#####c) In which window view can we track “counter” now?
Watch 1
#####d) What is the address of the “counter” variable in memory?
0x20000000
####6) Change the source code to the following, the run the program in the simulator:
#####a) What is the value of “counter” at the end of the program (halting at the return 0)?
4
#####b) Explain why the counter value has changed?
Counter is indirectly referenced when the pointer is dereferenced with *p_int.  Since p_int is dereferenced in parentheses first, the ++ operates on the
####7) Connect board to computer. Run the same code described in the simulator.
#####a) What is the address where “counter” is stored?
0x20000000
#####b) Is the “counter” variable stored in RAM or ROM.
RAM
#####c) What is the value of “counter” at the end of the program (halting at the return 0)?
4
