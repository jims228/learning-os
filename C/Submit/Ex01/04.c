#include<stdio.h>

int max(int a,int b){
    return (a>b) ? a : b;
}
int min(int a,int b){
    return(a<b) ? a : b;
}

int main(void){
    int i,n,max_p,min_p,current_p;

    scanf("%d",&n);
    scanf("%d",&current_p);
    min_p = current_p;
    scanf("%d",&current_p);

    max_p = current_p - min_p;
    min_p = min(min_p,current_p);

    for(i=0;i<n-2;i++){
        scanf("%d",&current_p);
        max_p = max(max_p, current_p - min_p);
        min_p = min(min_p, current_p);
    }
    printf("%d\n",max_p);
}