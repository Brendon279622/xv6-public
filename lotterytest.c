#include "types.h"
#include "user.h"
#include "pstat.h"

int
main(int argc, char *argv[])
{
  
  volatile int z = 0;
  
  void spin()
  {
    unsigned x = 0;
    unsigned y = 0;
    
    while (x < 1000000) {
      y = 0;
      while (y < (1000000)) {
        y++;
      }
      z += y + x;
      x++;
    }
  }
  
  
  int pid1, pid2, pid3;
  if ((pid1 = fork()) == 0) {
    
    settickets(10);
    spin();
    exit();
  }
  else if ((pid2 = fork()) == 0) {
    
    settickets(20);
    spin();
    exit();
  }
  else if ((pid3 = fork()) == 0) {
    
    settickets(30);
    spin();
    exit();
  }
  sleep(250);
  
  struct pstat ps;
  
  if(getpinfo(&ps)){
    printf(2, " failed\n" );
  }
  
  
  for (int i = 0; i < NPROC; ++i) {
    printf(2, "%d\t%d\t%d\t%d\n", ps.pid[i], ps.tickets[i], ps.inuse[i], ps.ticks[i]);
  }
  wait();
  wait();
  wait();
  
  
  exit();
}
