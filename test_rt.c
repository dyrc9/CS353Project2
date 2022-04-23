#include <sched.h>
#include <stdio.h>

int main(int argc,char *argv[]) 
{
  struct sched_param param; 
  int maxpri, count; 

  maxpri = sched_get_priority_max(SCHED_FIFO);
  if(maxpri == -1) { 
    perror("sched_get_priority_max() failed"); 
    return -1; 
  }
  printf("max priority of SCHED_FIFO is %d\n", maxpri);

  #if 1
  param.sched_priority = maxpri; 
  if (sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1) { 
    perror("sched_setscheduler() failed"); 
    return -1; 
  }
  #endif

  while(1) {
      count++;
  }

  return 0;
}
