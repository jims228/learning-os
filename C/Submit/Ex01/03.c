#include<stdio.h>
int main(){
    int i,j,n,num,count=0;
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    for(i=0;i<n;i++){
        num=array[i];

        if(num<=1){
            continue;
        }

        int is_sosuu = 1;
        for(j=2;j*j<=num;j++){
            if(num%j == 0){
                is_sosuu = 0;
                break;
            }
        }
        if(is_sosuu==1){
            count++;
        }
    }
    printf("%d\n",count);
}