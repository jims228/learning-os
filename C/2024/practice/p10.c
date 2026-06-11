// 10 J.txt
// 頂点数100の有向グラフ G 頂点番号は1..100
// 各頂点 u の隣接リストが1行で与えられる
// 形式は u k v1 v2 ... vk
// k は出次数で u から v1..vk に辺がある
// 頂点1から到達できない頂点の個数を出力する
//
// 方針
// 1 隣接行列 adj[u][v] を作る
//   adj[u][v]=1 なら u->v の辺がある
// 2 頂点1から DFS して visited[] を作る
//   visited[v]=1 なら 1から到達可能
// 3 visited[v]==0 の頂点数を数えて出力する
//
// DFSを使う理由
// 到達可能な頂点を一度ずつ訪問すればよいので実装が簡単
// 頂点数が100なので 隣接行列でも十分軽い
//
// 計算量
// DFSは最大で頂点100回
// 隣接行列なので各頂点で v=1..100 を走査し O(100*100) で余裕

#include <stdio.h>

#define MAXV 101

int n;
int adj[MAXV][MAXV];
int visited[MAXV];

// 頂点uから到達できる頂点を深さ優先で全部たどる
void dfs(int u){
    visited[u] = 1;

    // u から出る辺 u->v を全部見る
    for(int v=1; v<=n; v++){
        // 辺があり まだ未訪問なら v へ進む
        if(adj[u][v] && !visited[v]){
            dfs(v);
        }
    }
}

int main(void){
    n = 100;

    // 初期化
    for(int i=1;i<=n;i++){
        visited[i] = 0;
        for(int j=1;j<=n;j++){
            adj[i][j] = 0;
        }
    }

    // 入力を読み 隣接行列を作る
    for(int i=0;i<n;i++){
        int u,k;
        scanf("%d %d",&u,&k);
        for(int j=0;j<k;j++){
            int v;
            scanf("%d",&v);
            adj[u][v] = 1;
        }
    }

    // 始点は1
    dfs(1);

    // 到達不能な頂点数を数える
    int count = 0;
    for(int v=1; v<=n; v++){
        if(!visited[v]) count++;
    }

    printf("%d\n", count);
    return 0;
}
