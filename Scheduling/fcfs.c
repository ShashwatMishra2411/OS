#include <stdio.h>
// #include <conio.h
#include <stdlib.h>
#include <limits.h>

#define max 30

void completetime(int n, int at[max], int bt[max], int ct[max]){
    ct[0] = bt[0];
    int tt = 0;
    for(int k =0;k<n;k++){
    int i = 0;
    int min = INT_MAX;
    for(int j = 0;j<n;j++){
        if(at[j]<min){
            min = at[j];
            i = j;
        }
    }
    at[i] = INT_MAX;
    if(min>=tt)
    ct[i] = min + bt[i];
    else
    {
        ct[i] = tt + bt[i];
    }
    tt = ct[i];
    }

}

int main(){
    int n, ct[max], tat[max], wt[max];
    printf("Enter process\n");
    scanf("%d", &n);

    int a[max] = {0, 1, 5, 6};
    int b[max] = {2, 2, 3, 4};

    int at[max] = {0, 1, 5, 6};
    int bt[max] = {2, 2, 3, 4};

    completetime(n, at, bt, ct);
    float atat = 0.0;
    float awt = 0.0;
    for(int i;i<n;i++){
        tat[i] = ct[i] - a[i];
        wt[i] = tat[i] - b[i];
        atat += tat[i];
        awt += wt[i];
    }
    printf("%f - %f\n", atat/n, awt/n);
    return 0;
}