//素数の問題
//n 個の整数それぞれを素数判定して、素数だった個数を数える問題

//2は素数
//2より小さい数は素数ではない
//偶数は２以外全部だめ
//奇数だけ３からsqrtまで割り算して割り切れたらだめ

#include<stdio.h>

int isPrime(int x){
    // 2は素数
    if(x==2) return 1;

    // 2未満(0,1,負)は素数ではない
    if(x<2) return 0;

    // 偶数は2以外すべて合成数
    if(x%2==0) return 0;

    // 3,5,7,... の奇数だけで割り算を試す
    // i*i <= x まで見れば十分（sqrt(x)までと同じ意味）
    // long long にしてオーバーフローを防ぐ
    for(int i=3;(long long)i*i<=x;i+=2){
        // 割り切れたら約数があるので素数ではない
        if(x%i==0) return 0;
    }

    // どれでも割り切れなければ素数
    return 1;
}

int main(void){
    int n;
    scanf("%d",&n);

    int cnt=0;

    // n個の整数を読み込み、素数ならカウント
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);

        // isPrime(a)が1なら素数なのでcntを増やす
        if(isPrime(a)) cnt++;
    }

    // 素数の個数を1行で出力
    printf("%d\n",cnt);
    return 0;
}