//This program will blink LED1 to read PETER in Morse Code.

#if 1
//define the addresses for the clock gating and gpio registers
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
//have to typecast the address as an unsigned int then dereference it

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ODR5 (1<<5) //to toggle just bit 5 of the ODR

#define DOT 100000
#define DASH (DOT * 3)
#define CHARACTER_SPACE DOT
#define LETTER_SPACE (DOT * 2) //Although a letter space = 3 units in Morse Code, the dot and dash functions will end with a one unit character space.
#define WORD_SPACE (DOT * 6)  //Same as letter space above. Word space = 7 units = 1 unit character space from dot & dash functions + 6 units

volatile int counter = 0;

void dot(){
  
  //Turn LED on
  GPIOA_ODR |= ODR5;
  //Wait DOT length
  counter = 0;
  while (counter < DOT){
    counter++;
  } 
  //Turn LED off
  GPIOA_ODR &= ~ODR5;
  //Wait character space
  counter = 0;
  while (counter < CHARACTER_SPACE){
    counter++;
  }
}

void dash(){
  
  //Turn LED on
  GPIOA_ODR |= ODR5;
  //Wait DASH length
  counter = 0;
  while (counter < DASH){
    counter++;
  } 
  //Turn LED off
  GPIOA_ODR &= ~ODR5;
  //Wait character space
  counter = 0;
  while (counter < CHARACTER_SPACE){
    counter++;
  }
}

void endletter(){

    //wait letter space
    counter = 0;
    while (counter < LETTER_SPACE){
        counter++;
    }
}


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
     
    while(1){
      
        //Blink P = .--.
        dot();
        dash();
        dash();
        dot();
        endletter();
    
        //Blink E = .
        dot();
        endletter();
     
        //Blink T = -
        dash();
        endletter();
    
        //Blink E = .
        dot();
        endletter();
    
        //Blink R = .-.
        dot();
        dash();
        dot();
    
        //End word
        counter = 0;
        while (counter < WORD_SPACE){
            counter++;
        }
    }
}

#endif
