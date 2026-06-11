#include<stdio.h>
int main(){
    int n,i,j,u,k,v,adj[101][101]={0};
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d %d",&u,&k);
        for(j=0;j<k;j++){
            scanf("%d",&v);
            adj[u-1][v-1]=1;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",adj[i][j]);
            if(!(j==n-1)) printf(" ");
        }
        printf("\n");
    }
}