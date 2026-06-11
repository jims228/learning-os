//BFS
#include <stdio.h>

#define MAXN 100

int main(void){
    int n;
    scanf("%d",&n);

    // 隣接行列 adj[u][v] = 1 なら u -> v の辺がある
    int adj[MAXN+1][MAXN+1];
    for(int i=1;i <= n;i++){
        for(int j=1;j <= n;j++){
            adj[i][j]=0;
        }
    }

    // 入力を隣接行列に入れる
    for(int i=0;i < n;i++){
        int u,k;
        scanf("%d %d",&u,&k);
        for(int j=0;j < k;j++){
            int v;
            scanf("%d",&v);
            adj[u][v]=1;
        }
    }

    // dist[i] = 始点1からiへの最短距離
    // 未到達は -1
    int dist[MAXN+1];
    for(int i=1;i <= n;i++){
        dist[i]=-1;
    }

    // BFS用キュー
    int q[MAXN*MAXN];
    int head=0;
    int tail=0;

    // 始点は1
    dist[1]=0;
    q[tail++]=1;

    while(head < tail){
        int u=q[head++];

        // 頂点番号が小さい順に見る
        for(int v=1;v <= n;v++){
            if(adj[u][v] == 1 && dist[v] == -1){
                dist[v]=dist[u]+1;
                q[tail++]=v;
            }
        }
    }

    // 指定通り 1..n の順に出力
    for(int i=1;i <= n;i++){
        printf("%d %d\n",i,dist[i]);
    }

    return 0;
}
