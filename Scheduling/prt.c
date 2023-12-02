#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
    int at[10] = {0,1,2,3}, bt[10] = {3,1,1,2}, rt[10] = {3,1,1,2},prt[10] = {4,1,2,3},ct, i, smallest;
    int remain = 0, n = 4, time, swt = 0, stat = 0;

    for(time = 0;remain!=n;time++){
        int srt = INT_MAX;
        for(i = 0;i<n;i++){
            if(at[i]<=time && rt[i]){
                if(prt[i]<srt){
                    srt = prt[i];
                    smallest = i;
                }
            }
        }
        rt[smallest]--;
        if(rt[smallest] == 0){
            remain++;
            ct = time+1;
            printf("%d\t%d\t%d\n", smallest+1, ct-at[smallest], ct-at[smallest]-bt[smallest]);
            swt = swt+ ct-at[smallest]-bt[smallest];
            stat = stat + ct-at[smallest];
        }
    }

    return 0;
}