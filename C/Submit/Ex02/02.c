#include<stdio.h>

int main(){
    int i,j,n,minj,temp,count=0;
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    //まだ整列してないとこから最小値を探す?よくわかってない
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(array[j]<array[minj]){
                minj = j;
            }
        }
        if(i != minj){
            temp = array[i];
            array[i] = array[minj];
            array[minj] = temp;

            count++;
        }

    }
    
    for(i=0;i<n;i++){
        printf("%d",array[i]);
        if(i != n-1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",count);
}