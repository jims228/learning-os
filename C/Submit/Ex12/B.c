#include<stdio.h>

#define MAXN 101
#define INF 100000000

int main(void){
    int n;
    int w[MAXN][MAXN];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            w[i][j]=INF;
        }
    }

    int u,k,v,c;
    for(int i=0;i<n;i++){
        scanf("%d %d",&u ,&k);
        for(int j=0;j<k;j++){
            scanf("%d %d",&v ,&c);
            w[u][v]=c;
        }
    }

    long long dist[MAXN];//dist[v]は始点0からvまでの最短距離の暫定値
    int used[MAXN];//その頂点の最短距離が確定済みかどうか
    for(int i=0;i<n;i++){
        dist[i]=INF;
        used[i]=0;
    }
    dist[0]=0;

        for (int it=0;it<n;it++) {
        int minv = -1;
        long long best = INF;

        for (int v=0;v<n;v++) {
            if (!used[v] && dist[v] < best) {
                best = dist[v];
                minv = v;
            }
        }

        if (minv == -1) break;
        used[minv]=1;

        for (int v=0;v<n;v++) {
            if (w[minv][v] == INF) continue;
            if (dist[v] > dist[minv] + w[minv][v]) {
                dist[v] = dist[minv] + w[minv][v];
            }
        }
    }

    for(int v=0;v<n;v++){
        printf("%d %lld\n",v,dist[v]);
    }
    return 0;
}