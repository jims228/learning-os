#include<stdio.h>
int bubbleSort(int A[],int n){
    int count=0;
    int flag=1;
    int j;
    while(flag){
        flag=0;
        for(j=n-1;j>0;j--){
            if(A[j]<A[j-1]){
                int buf;
                buf=A[j];
                A[j]=A[j-1];
                A[j-1]=buf;
                count++;
                flag=1;
            }
        }
    }
    return count;
}

int main(void){
    int n;
    int count;
    int A[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    count=bubbleSort(A,n);
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d",count);
    printf("\n");
    return 0;
}