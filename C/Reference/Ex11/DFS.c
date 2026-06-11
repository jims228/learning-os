//DFS

#include <stdio.h>

#define MAXN 101

int n;
int adj[MAXN][MAXN]; // adj[u][v]=1 なら u->v の辺がある
int color[MAXN];     // 0:white(未訪問) 1:gray(探索中) 2:black(探索完了)
int d[MAXN],f[MAXN]; // d[u]=発見時刻 f[u]=完了時刻
int t=0;             // 時刻（スタンプ）

void dfs_visit(int u){
    // u を発見した瞬間
    color[u]=1;
    t++;
    d[u]=t;

    // 隣接頂点を番号が小さい順に見る
    for(int v=1;v <= n;v++){
        // 辺があって、まだ未訪問なら深く潜る
        if(adj[u][v] == 1 && color[v] == 0){
            dfs_visit(v);
        }
    }

    // u の隣接を全部見終わった瞬間
    color[u]=2;
    t++;
    f[u]=t;
}

int main(void){
    scanf("%d",&n);

    // 隣接行列を0で初期化
    for(int i=1;i <= n;i++){
        for(int j=1;j <= n;j++){
            adj[i][j]=0;
        }
    }

    // 入力 u k v1 v2 ... vk を読み、u->v の辺を入れる
    for(int i=0;i < n;i++){
        int u,k;
        scanf("%d %d",&u,&k);
        for(int j=0;j < k;j++){
            int v;
            scanf("%d",&v);
            adj[u][v]=1;
        }
    }

    // 初期化
    for(int i=1;i <= n;i++){
        color[i]=0;
        d[i]=0;
        f[i]=0;
    }
    t=0;

    // 1から順に、未訪問ならそこを新しい開始点としてDFS
    for(int u=1;u <= n;u++){
        if(color[u] == 0){
            dfs_visit(u);
        }
    }

    // 指定通り、頂点番号順に id d f を出力
    for(int i=1;i <= n;i++){
        printf("%d %d %d\n",i,d[i],f[i]);
    }

    return 0;
}
