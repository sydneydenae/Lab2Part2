/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

volatile int alarm_count = 0;
time_t start_time;

void handler1(int signum) {
    alarm_count++;
}

void handler2(int signum)
{
 time_t end_time = time(NULL);
  double total_time = difftime(end_time, start_time);
  printf("Total execution time: %d\n Total alarms: %d\n\n", total_time, alarm_count);
  exit(0);
}

int main(int argc, char * argv[])
{
start_time = time(NULL);
time_t seconds;
seconds = time(NULL);

signal(SIGALRM,handler1); 
signal(SIGINT,handler2);
alarm(5); // Schedule a SIGALRM for 5 seconds
while(1){
    alarm(1);  // Schedule the next alarm
    pause();
}
  return 0; //never reached
}