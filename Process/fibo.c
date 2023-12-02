#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5;
    int f = 1;
    for(int i = 1; i<=5; i++){
        f=f*i;
    }
    printf("%d\n", f);
    return 0;
}