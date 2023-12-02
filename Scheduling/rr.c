#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n = 4, at[10] = {0,1,2,4}, bt[10] = {5,4,2,1},rt[10] = {5,4,2,1}, ct, turn, swap = 1, time = 0, remain = 0, q[10], rear = 0, front = 0, swt = 0, stat = 0;
    for(time = 0; remain!=n; time++){
        for(int i = 0;i<n;i++){
            if(at[i]<=time&&rt[i]){
                q[front] = i;
                front++;
                if(swap){
                    turn = q[rear];
                    rear++;
                    swap = 0;
                }
            }
        }
        rt[turn]--;
        if(rt[turn] == 0){
            remain++;
            ct = time+1;
            printf("%d\t%d\t%d\n", turn+1, ct-at[turn], ct-at[turn]-bt[turn]);
            swt = swt+ ct-at[turn]-bt[turn];
            stat = stat + ct-at[turn];
            swap = 1;
        }
        else if(time % 2 == 0 && rt[turn] != 0 && time != 0){
            swap = 1;
            q[front] = turn;
            front++;
        }
    }
}