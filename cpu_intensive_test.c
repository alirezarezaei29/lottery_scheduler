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
#define CONSTANT 500000


int main(int argc, char **argv){

    int base = 10;
    int exponent = 5 ;
    long long result = 1;
    while (exponent != 0)
    {
       if(exponent < 3){
           fork(0);
       }
        result *= base;
        --exponent;
    }



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
    printf(1, "first_res_time : %d \n", first_res_time - ctime);
    printf(1, "test : %d \n", table.counts[3]);
    printf(1, "TurnAroundTime : %d\n",ltime-ctime );


    exit();
    // struct *proc p ;
    //call sys_call
    // print pid and times

}
