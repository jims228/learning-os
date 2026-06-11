#include<stdio.h>

int main(){
    int flag=1,j,n,temp,count=0;

    scanf("%d",&n);
    int array[n];
    for(j=0;j<n;j++){
        scanf("%d",&array[j]);
    }

    while(flag){
        flag = 0;
        for(j=n-1;j>=1;j--){
            if(array[j] < array[j-1]){
                temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
                flag=1;
                count++;
            }
        }
    }

    for(j=0;j<n;j++){
        printf("%d",array[j]);
        if(j != n-1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",count);
}