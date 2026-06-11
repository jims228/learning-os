// 12. L.txtには頂点数が100個の重み付き有向グラフGの情報が書かれている。
// 入力は100×100の行列からなる。
// 各頂点には1から100までの番号が振られており、行列の要素 a_ij が頂点 i から頂点 j に向かう辺の距離（重み）を示す。
// i と j の間に辺がない場合 a_ij は 10^9 で表され、辺がある場合は 0 ≤ a_ij ≤ 1,000 である。
// 頂点1からの最短経路の距離が最も長い頂点の番号を求めよ。
// そのような頂点はちょうど1つあり、頂点1からはどの頂点へもたどり着くことができる。

#include<stdio.h>

#define N 100
#define INF 1000000000LL

int main(void){
    long long w[N+1][N+1];

    // 入力
    // w[i][j] は i から j への辺の重み
    // 辺が無いとき w[i][j] は 1000000000
    for(int i=1;i <= N;i++){
        for(int j=1;j <= N;j++){
            scanf("%lld",&w[i][j]);
        }
    }

    long long dist[N+1];
    int used[N+1];

    // dist[v] は 頂点1からvまでの最短距離の暫定値
    // used[v] は 最短距離が確定済みなら1
    for(int v=1;v <= N;v++){
        dist[v]=INF;
        used[v]=0;
    }
    dist[1]=0;

    // ダイクストラ法
    // 確定していない頂点の中で dist が最小の頂点 u を選ぶ
    // u を確定して u から出る辺で dist を更新する
    for(int it=1;it <= N;it++){
        int u=-1;
        long long best=INF;

        // 次に確定する頂点 u を探す
        for(int v=1;v <= N;v++){
            if(used[v] == 0 && dist[v] < best){
                best=dist[v];
                u=v;
            }
        }

        // 全頂点へ到達できる前提なので u は必ず見つかる
        used[u]=1;

        // u から v への辺があるなら緩和する
        // dist[v] > dist[u] + w[u][v] のとき dist[v] を更新
        for(int v=1;v <= N;v++){
            if(w[u][v] != INF){
                if(used[v] == 0 && dist[v] > dist[u] + w[u][v]){
                    dist[v]=dist[u] + w[u][v];
                }
            }
        }
    }

    // 頂点1からの最短距離が最大になる頂点を探す
    // 最大になる頂点は1つだけという条件
    int ans=1;
    for(int v=2;v <= N;v++){
        if(dist[v] > dist[ans]){
            ans=v;
        }
    }

    // 出力は頂点番号だけ
    printf("%d\n",ans);
    return 0;
}
