#include<stdio.h>
int main(){
    int x,y,buf,a,b;
    scanf("%d %d",&x, &y);
    if(x>=y){a=x,b=y;}
    else    {a=y,b=x;}
    while(b!=0){
        buf=a%b;
        a=b;
        b=buf;
    }
    printf("%d\n",a);
    return 0;
}