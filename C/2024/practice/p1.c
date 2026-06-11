// 1 A.txt
// 空白区切りで整数 a0 a1 ... a10000 が並ぶ 0<=ai<=1e9
// x = a10000 とする
// 先頭から線形探索したとき x と等しくなる最小の i を出力する

// gcc -O2 -std=c11 -Wall -Wextra p1.c -o p1
// ./p1 < A.txt
#include<stdio.h>

int main(void){
    int n;
    int i=0;
    int A[10002];

    n=10001;
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    int x=A[10000];
    A[n]=x;
    while(A[i] != x) i++;

    printf("%d\n",i);
    return 0;
}