#include "types.h"
#include "user.h"

int
main(int argc, char* argv[])
{
  if(argc != 3){
    printf(2,"usage: syscalls N g\n");
    exit();
  }
  int total = atoi(argv[1]);
  int good = atoi(argv[2]);
  if((total < 1) || (good < 1) || (good > total)){
    printf(2,"invalid argument\n");
    exit();
  }
  int pid = getpid();
  for(int i = 0; i < good - 1; i++){
    getpid();
  }
  for(int j = 0; j < total - good; j++){
    kill(-1);
  }
  int realTotal = getnumsyscalls(pid);
  int realGood = getnumsyscallsgood(pid);
  printf(1,"%d %d\n", realTotal, realGood);
  exit();
}
