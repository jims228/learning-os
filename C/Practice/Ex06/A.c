#include<stdio.h>

#define MAXN 2000005
#define MAXV 10005

int A[MAXN];
int B[MAXN];
int C[MAXV+1];
int n;
void CountingSort(int n,int k){
    for(int i=0;i<=k;i++) C[i]=0;
    for(int j=0;j<n;j++) C[A[j]]++;
    for(int i=1;i<=k;i++) C[i]=C[i]+C[i-1];
    for(int j=n-1;j>=0;j--){
        B[--C[A[j]]] = A[j];
    }
}

int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    CountingSort(n,MAXV);

    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",B[i]);
    }
    printf("\n");

    return 0;
}