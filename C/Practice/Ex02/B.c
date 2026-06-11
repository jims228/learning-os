#include<stdio.h>
int selectionSort(int A[],int n){
    int i,j,buf,count=0;
    for(i=0;i<n;i++){
        int minj = i;
        for(j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            buf=A[i];
            A[i]=A[minj];
            A[minj]=buf;
            count++;
        }
    }
    return count;
}
int main(void){
    int n;
    int A[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    int count=selectionSort(A,n);
    for(int i=0;i<n;i++){
       if(i) printf(" ");
       printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}