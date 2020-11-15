
int counter = 0x0;
int main()
{
  int *p_int = (int *)0x20000000; /* "p_int" is an int pointer that equals the value at address 0x2000000. 
                                    Could have also written = &counter since this is the address of counter as seen in the Watch 1 view */
  ++(*p_int);           /* increments the value of what p_int is pointing to i.e. value of counter. */
  ++(*p_int);
  ++(*p_int);
  counter ++;
  return 0;
}
