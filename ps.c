#include "types.h"
#include "user.h"
#include "pstat.h"





int
main(int argc, char *argv[])
{

  struct pstat ps;
  if(getpinfo(&ps)){
    printf(2, " failed\n" );
  }
  printf(2,"%s\t%s\t%s\t%s\n","pid","tickets", "inuse", "ticks" );
  printf(2,"\n");
  for (int i = 0; i < NPROC; ++i) {
    printf(2, "%d\t%d\t%d\t%d\n", ps.pid[i], ps.tickets[i], ps.inuse[i], ps.ticks[i]);
  }

  exit();

}



