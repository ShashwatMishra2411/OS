#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int np, nr;
int max[10][10], allocation[10][10], need[10][10];
int avail[10];

void readmatrix(int matrix[10][10]){
    int i, j;
    for(i = 0; i<np; i++){
    for(j = 0; j<nr; j++){
        scanf("%d", matrix[i][j]);
    }
    }
}

void display_matrix(int matrix[10][10]){
    for(int i = 0;i<np;i++){
        printf("\n P%d", i);
        for(int j = 0; j<nr; j++){
            printf(" %d",matrix[i][j]);
        }
    }
}

void calculate_need(){
    int i, j;
    for(i = 0; i<np; i++){
    for(j = 0; j<nr; j++){
        need[i][j] = max[i][j] - allocation[i][j];
    }
    }
}

void banker(){
    int finish[10], safe_seq[10];
    int k = 0, flag = 0;
    for(int i = 0;i<np;i++){
        finish[i] = 0;
    }
    for(int i = 0;i<np;i++){
        flag = 0;
        if(finish[i] == 0){
            for(int j = 0;j<nr;j++){
                if(need[i][j]>avail[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                finish[i] = 1;
                safe_seq[k] = i;
                k++;
                for(int j = 0;j<nr;j++){
                    avail[j] += allocation[i][j];
                }
                i = -1;
            }
        }
    }
    flag = 0;
    for(int i = 0;i<np;i++){
        if(finish[i] == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        for(int i =0 ;i<np;i++){
            printf("%d-", safe_seq[i]);
        }
    }
}

int main(){

    np = 4;
    nr = 3;

    readmatrix(allocation);
    readmatrix(max);
     
    display_matrix(allocation);
    display_matrix(max);

    calculate_need();
    display_matrix(need);

    banker();
    return 0;
}