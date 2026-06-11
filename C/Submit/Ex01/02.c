#include<stdio.h>

int main(){
    int x,y,a;
    scanf("%d %d",&x,&y);
    while(y != 0){
        a=x%y;
        x=y;
        y=a;
    }
    printf("%d\n",x);
}