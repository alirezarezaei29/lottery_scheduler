#include "types.h"
#include "param.h"
#include "stat.h"
#include "user.h"


#define MAX 1123
#define nprocs 10

int main(void){
  int i, tpids[nprocs];
  for(i=0; i <= nprocs; i++){
    tpids[i]=fork(nprocs%4);
    if(tpids[i] == 0){
      for(int j=0; j< MAX; j++);
      exit();
    }
    for(i=0; i < nprocs; i++){
    wait();
    exit();
  }
}
  return 0;
}
