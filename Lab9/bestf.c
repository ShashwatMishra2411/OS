#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    // int process[] = {212, 417, 112, 426};
    int process[10] = {212, 417, 112, 426};
    int block[] = {100, 500, 200, 300, 600};
    int blockid[10];
    int p = 4, b = 5;
    int min = INT_MAX;
    int mins = INT_MAX;
    // printf("%d\n", process[0]);
    for(int i = 0;i<p;i++){
        mins = INT_MAX;
        for(int j = 0;j<b;j++){
            // printf("%d\n", process[i]);
            if(block[j]>=process[i]&&block[j]<=mins){
                mins = block[j];
                min = j;
                printf("%d = %d\n", process[i],block[j]);
            }
        }
        block[min] = block[min] - process[i];
        blockid[i] = min;
    }
    for(int i = 0 ;i<p;i++){
        printf("%d-%d ", blockid[i], block[i]);
    }
    return 0;
}