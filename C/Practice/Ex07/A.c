/*
1 parent 配列を作る
2 root を特定する
3 root から深さ depth を求める
4 ノード種別 root / internal node / leaf を決める
5 指定フォーマットで 0 から n-1 の順に出力
*/

//ノードとは頂点のこと
//ノードidには、子ノードがk個あって、その子たちはc1,c2,...,ckですよ～

#include <stdio.h>

#define MAXN 100000

int parent[MAXN];//ノード i の親の番号。根だけ -1
int depth[MAXN];//根から i までの深さ
int head[MAXN];//child 配列の中で、ノード i の子リストが始まる位置
int deg[MAXN];//ノード i の子の人数
int child[MAXN];//全ノードの子を 1 本の配列に詰めたもの
int q[MAXN];//BFS 用のキュー

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        deg[i] = 0;
        head[i] = 0;
        depth[i] = 0;
    }

    int pos = 0;

    for (int i = 0; i < n; i++) {
        int id, k;
        scanf("%d %d", &id, &k);

        head[id] = pos;//このノードの子リストは child 配列の pos から始まると覚える
        deg[id] = k;//子の数を記録

        for (int j = 0; j < k; j++) {
            int c;
            scanf("%d", &c);
            child[pos++] = c;//子を 1 個読むたびに pos を 1 増やす
            parent[c] = id;//parent を入力から復元
        }
    }

    int root = -1;
    //全部読んだ後、parent[i] が -1 のノードが根
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }

    //BFSでdepth
    // ・キューに root を入れる
    // ・取り出した u の子 v 全員に対して
    // depth[v] = depth[u] + 1
    // キューに v を入れる
    int front = 0, back = 0;
    q[back++] = root;
    depth[root] = 0;

    while (front < back) {
        int u = q[front++];
        for (int i = 0; i < deg[u]; i++) {
            int v = child[head[u] + i];
            depth[v] = depth[u] + 1;
            q[back++] = v;
        }
    }

    // 出力 node i: parent = p, depth = d, type, [子リスト]
    for (int i = 0; i < n; i++) {
        const char *type;
        if (parent[i] == -1) type = "root";//parent[i] が -1 なら root
        else if (deg[i] == 0) type = "leaf";//そうでなく deg[i] が 0 なら leaf
        else type = "internal node";//それ以外は internal node

        printf("node %d: parent = %d, depth = %d, %s, [", i, parent[i], depth[i], type);

        for (int j = 0; j < deg[i]; j++) {
            if (j) printf(", ");
            printf("%d", child[head[i] + j]);
        }
        printf("]\n");
    }

    return 0;
}
