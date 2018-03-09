#include <time.h>
#include "timer.h"
#include <stdlib.h>

static time_t var_start_time=-1;

void start_timer(void){
  var_start_time=time(0);
}

void stop_timer(void){
  var_start_time=-1;
}

//checks if time since "start_timer" is greater than 3 seconds. returns 1 if true, 0 if false and -1 if timer is not yet started.
int timer_is_timeout(void){
  if (var_start_time<0){
    return -1;
  }
  time_t time_now =time(0);
  if(time_now-var_start_time>3){
    stop_timer();
    return 1;
  }
  return 0;
}
