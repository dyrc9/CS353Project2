#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(){
    int count;
    int i;
    pid_t pid;
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(2, &mask);
    sched_setaffinity(0, sizeof(mask), &mask);

    for(i=0; i<9; i++){
        pid = fork();
        if(pid == 0) {
            sched_setaffinity(0, sizeof(mask), &mask);
            break;
        }
    }
    if(i<9){
        printf("I am %d child, pid = %u\n", i+1, getpid());
    }
    else{
        printf("I am parent/n");
    }
    
    while(1){
        count ++;
    }
    return 0;
}
