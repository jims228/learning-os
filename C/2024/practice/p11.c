// 11. K.txtには各行に1つ，合計10^6個の整数 a_i (0 ≤ a_i ≤ 10^9) が書かれている。
// P を値の小さいものから取り出す優先度付きキューとする。
// a_i を順番に読み込み，a_i > 0 のとき P に a_i を挿入し，a_i = 0 のとき P から1つの整数を取り出す
// このとき P には1つ以上の要素があると仮定してよい
// 取り出された要素の合計値を答えよ
// 答えは非常に大きくなり得ることに注意せよ

#include<stdio.h>

#define MAXQ 1000005

long long heap[MAXQ];
int hsize=0;

// ヒープに値 x を追加する
// 最小値が先頭 heap[1] に来るように上へ調整する
void push(long long x){
    int i=++hsize;
    heap[i]=x;

    while(i > 1){
        int p=i/2;
        if(heap[p] <= heap[i]) break;

        long long tmp=heap[p];
        heap[p]=heap[i];
        heap[i]=tmp;

        i=p;
    }
}

// ヒープから最小値を取り出す
// 先頭を取り出して最後の要素を先頭に移し，下へ調整する
long long pop(void){
    long long ret=heap[1];

    heap[1]=heap[hsize];
    hsize--;

    int i=1;
    while(1){
        int l=i*2;
        int r=i*2+1;
        int s=i;

        if(l <= hsize && heap[l] < heap[s]) s=l;
        if(r <= hsize && heap[r] < heap[s]) s=r;

        if(s == i) break;

        long long tmp=heap[i];
        heap[i]=heap[s];
        heap[s]=tmp;

        i=s;
    }

    return ret;
}

int main(void){
    long long x;
    long long sum=0;

    // 入力は10^6行だが，行数を数えなくても EOF まで読めばよい
    while(scanf("%lld",&x) == 1){
        if(x > 0){
            // 正の値は優先度付きキューに入れる
            push(x);
        }else{
            // 0 のとき最小値を取り出して合計に足す
            // このときキューは空ではないと仮定してよい
            sum += pop();
        }
    }

    printf("%lld\n",sum);
    return 0;
}
