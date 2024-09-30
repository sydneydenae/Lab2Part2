/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

volatile bool signal_handled = false;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  signal_handled = true;
}

int main(int argc, char * argv[])
{
signal(SIGALRM,handler); //register handler to handle SIGALRM
alarm(5); // Schedule a SIGALRM for 5 seconds
while(1){
  if(signal_handled){
    printf("Turing was right!\n");
    signal_handled = false;
    alarm(5);  // Schedule the next alarm
  }
}
  return 0; //never reached
}