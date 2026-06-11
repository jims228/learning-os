//単一始点最短経路の問題
//ダイクストラ法 で 始点 0 から各頂点までの最短距離を求める処理
//Gの頂点０を始点都市、０から各頂点ｖについて、最短経路上の重みの総和d[v]を出力する

// 有向グラフ
// 辺の重みは 0 以上
// 入力は隣接リスト形式だが コード内では隣接行列に直している

// 1 グラフの入力を受け取って 辺の重み表 w を作る
// 2 dist 配列に 最短距離の暫定値 を入れる
// 3 used 配列で その頂点の最短距離が確定したか を管理する
// 4 まだ確定していない頂点のうち dist が最小の頂点を選ぶ
// 5 その頂点から出る辺で 他の頂点の dist を更新する
// 6 これを n 回繰り返す
// 7 dist を出力する

#include<stdio.h>

#define MAXN 101
#define INF 100000000

int main(void){
    int n;
    int w[MAXN][MAXN];//w は 辺の重み表。w の u 行 v 列 が u から v への辺の重み。

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