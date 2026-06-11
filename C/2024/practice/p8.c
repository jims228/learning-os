// 8 H.txt
// 節点数44の2分木 T がある 節点番号は0..43
// 入力は44行 各行は vi li ri
// vi は節点番号 li は左の子 ri は右の子
// 子がない場合 li または ri は -1
// 根の深さを0として 深さが4以上の節点の個数を出力する
// 節点0が根とは限らない
//
// 方針
// 1 left[v], right[v] に子を保存する
// 2 isChild[] を使って根を特定する
//   子として1回でも登場した節点は isChild[child]=1
//   isChild[v]==0 の節点が根
// 3 根から BFS で各節点の深さ depth[v] を求める
//   depth[root]=0
//   親uから子cへ行くと depth[c]=depth[u]+1
// 4 depth[v]>=4 の個数を数えて出力する
//
// BFSを使う理由
// 深さが自然に 0,1,2,... と伝播していくので実装が簡単で安全
// 節点数44なので DFSでもよいが キューで書くとバグりにくい

#include <stdio.h>

int main(void){
    int left[44], right[44];
    int isChild[44] = {0};

    // 子情報の初期化
    for(int i=0;i<44;i++){
        left[i] = -1;
        right[i] = -1;
    }

    // 入力を読みながら
    // left/right を埋めて 子になった節点に印を付ける
    for(int i=0;i<44;i++){
        int v, l, r;
        scanf("%d %d %d", &v, &l, &r);

        left[v] = l;
        right[v] = r;

        if(l != -1) isChild[l] = 1;
        if(r != -1) isChild[r] = 1;
    }

    // 根を探す 節点0が根とは限らないので必ず isChild から求める
    int root = -1;
    for(int v=0;v<44;v++){
        if(isChild[v] == 0){
            root = v;
            break;
        }
    }

    // depth[v] を -1 で初期化 未到達の印
    int depth[44];
    for(int v=0;v<44;v++) depth[v] = -1;

    // BFS用キュー
    int q[44];
    int head = 0, tail = 0;

    // BFS開始
    depth[root] = 0;
    q[tail++] = root;

    while(head < tail){
        int u = q[head++];

        // 左の子
        int l = left[u];
        if(l != -1){
            depth[l] = depth[u] + 1;
            q[tail++] = l;
        }

        // 右の子
        int r = right[u];
        if(r != -1){
            depth[r] = depth[u] + 1;
            q[tail++] = r;
        }
    }

    // 深さ4以上の節点数を数える
    int count = 0;
    for(int v=0;v<44;v++){
        if(depth[v] >= 4) count++;
    }

    printf("%d\n", count);
    return 0;
}
