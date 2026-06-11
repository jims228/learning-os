//最大ヒープを作る問題。入力の配列を最大ヒープの形に並び替えて、配列として出力する。
//ヒープは完全二分木の形をしたデータ構造。完全二分木は上から順に左詰めでノードが埋まる木。

//最大ヒープの条件は「親の値がこの値以上」
//根が必ず最大

// 親 i の左の子は 2i
// 親 i の右の子は 2i+1
// 子 i の親は i/2

#include <stdio.h>

#define MAXN 200000

int A[MAXN+1];

void maxHeapify(int i,int n){
    // i を根とする部分木が最大ヒープになるように直す
    // 子の方が大きければ交換して、落ちた先でも同じことを繰り返す
    while(1){
        int l=2*i;       // 左の子
        int r=2*i+1;     // 右の子
        int largest=i;   // 最大の値を持つ位置

        // 左の子が存在して、親より大きいなら largest を左にする
        if(l <= n && A[l] > A[largest]) largest=l;

        // 右の子が存在して、largest より大きいなら largest を右にする
        if(r <= n && A[r] > A[largest]) largest=r;

        // 親が最大ならもう直す必要がない
        if(largest == i) break;

        // 親と最大の子を交換
        int tmp=A[i];
        A[i]=A[largest];
        A[largest]=tmp;

        // 交換で落ちた位置から続き
        i=largest;
    }
}

void buildMaxHeap(int n){
    // 下から順に直す
    // n/2 以降は葉なので不要
    for(int i=n/2;i >= 1;i--){
        maxHeapify(i,n);
    }
}

int main(void){
    int n;
    scanf("%d",&n);

    for(int i=1;i <= n;i++){
        scanf("%d",&A[i]);
    }

    buildMaxHeap(n);

    // 出力は各要素の前に空白を入れる形式
    for(int i=1;i <= n;i++){
        printf(" %d",A[i]);
    }
    printf("\n");

    return 0;
}
