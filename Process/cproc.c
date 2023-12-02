#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t pid, mypid, myppid;
    pid = getpid();
    printf("PID before: %d\n", pid);

    pid = fork();
    if(pid == 0){
        printf("Child is running\n");
        sleep(3);
        printf("chi = %d\n", getpid());
        exit(0);
    }
    else{

        pid_t sc = fork();
        if(sc == 0){
            printf("Child2 is running\n");
            sleep(2);
            printf("chi2 = %d\n", getpid());
            exit(0);
        }
        else{
            printf("Parent waiting for child\n");
            waitpid(sc, NULL, 0);
            waitpid(pid, NULL, 0);
            execl("fibo", "fibo.exe", NULL);
        }
        
    }
    return 0;
}