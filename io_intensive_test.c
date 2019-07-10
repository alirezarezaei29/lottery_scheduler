#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"
#include "table.h"

char buf[8192];
char name[3];
char *echoargv[] = { "echo", "ALL", "TESTS", "PASSED", 0 };
int stdout = 1;

void
writetest1(void)
{
  int i, fd, n;

  printf(stdout, "big files test\n");

  fd = open("big", O_CREATE|O_RDWR);
  if(fd < 0){
    printf(stdout, "error: creat big failed!\n");
    exit();
  }

  for(i = 0; i < MAXFILE; i++){
    ((int*)buf)[0] = i;
    if(write(fd, buf, 512) != 512){
      printf(stdout, "error: write big file failed\n", i);
      exit();
    }
  }

  close(fd);

  fd = open("big", O_RDONLY);
  if(fd < 0){
    printf(stdout, "error: open big failed!\n");
    exit();
  }

  n = 0;
  for(;;){
    i = read(fd, buf, 512);
    if(i == 0){
      if(n == MAXFILE - 1){
        printf(stdout, "read only %d blocks from big", n);
        exit();
      }
      break;
    } else if(i != 512){
      printf(stdout, "read failed %d\n", i);
      exit();
    }
    if(((int*)buf)[0] != n){
      printf(stdout, "read content of block %d is %d\n",
             n, ((int*)buf)[0]);
      exit();
    }
    n++;
  }
  close(fd);
  if(unlink("big") < 0){
    printf(stdout, "unlink big failed\n");
    exit();
  }
  printf(stdout, "big files ok\n");
}

int main(){
writetest1();

    struct table table;
    int n = counts(&table);
    // if error
    if (n < 0) {
        return -1;
    }
    printf(1,"TESTTT\n");
    int ctime = table.counts[0];
    int ltime = table.counts[1];
    int first_res_time = table.counts[2];
    printf(1, "ctime : %d \n", table.counts[0]);
    printf(1, "ltime : %d \n", table.counts[1]);
    printf(1, "first_res_time : %d \n", table.counts[2]);
    printf(1, "test : %d \n", table.counts[3]);
    printf(1, "TurnAroundTime : %d\n",ltime-ctime );
    printf(1, "ResponseTime : %d\n", ltime-first_res_time);

exit();
}
