//This program will blink LED1 using the XOR bitwise function.

#if 1
//define the addresses for the clock gating and gpio registers
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
//have to typecast the address as an unsigned int then dereference it

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ODR5 (1<<5) //to toggle just bit 5 of the ODR

volatile int counter = 0;
void main(void)
{
  
    /*Enable clock
    Set bit[0] of RCC_AHB2ENR to 1.
    Write 0x0000 0001 to address 0x4002104C (Reset value of register is 0x0000000)
    *(unsigned int*)0x4002104C = 0x1*/
  
    RCC_AHB2ENR |= 0x1; //use an OR to avoid overwriting the other bits.
 
    /* Change mode of PA5 to output 
    Set bits[11:10] of GPIOA_MODER to 01 i.e. clear bit 11
    Change value from 0xABFF FFFF (reset value) to  ABFF F7FF
    *(unsigned int*)0x48000000 = 0xABFFF7FF */
    
    GPIOA_MODER &= 0xFFFFF7FF; //using AND will only clear bit 11.
    
    //Change GPIO port output data register (GPIOA_ODR) bit5 to turn LED on (1) and off(0) 
     
       while(1)
    {
        counter=0;
        while (counter < 100000)
        {
          counter++;
        }
        GPIOA_ODR ^= ODR5; //XOR will always toggle LED
        counter=0;

    } 
     
}

#endif
