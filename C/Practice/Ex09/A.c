#include<stdio.h>
int main(void){
    int H;
    long long A[251];
    scanf("%d",&H);
    for(int i=1;i<=H;i++) scanf("%lld",&A[i]);
    for(int i=1;i<=H;i++){
        printf("node %d: key = %lld, ",i,A[i]);
        if(i/2>=1)printf("parent key = %lld, ",A[i/2]);
        if(i*2<=1)printf("left key = %lld, ",A[2*i]);
        if(2*i+1<=H)printf("right key = %lld, ",A[2*i+1]);
    }
    return 0;
}