// 7 G.txt
// 異なる整数 a1..a12 が書かれている 1<=ai<=500
// それぞれの額面の紙幣を1枚ずつ持っている
// ちょうど500円を支払う方法の数を出力する


#include<stdio.h>

int main(){
    int a[12];
    
    for(int i=0;i<12;i++) scanf("%d",&a[i]);
    
    int count=0;
    //1<<12 は「1 を左に 12 ビットずらす」という意味
    //つまり左に k 回ずらすと 2^k
    //つまりmask=0;mask<4096;mask++

    //2ビットで表して0なら選ばない1なら選ぶ

    for(int mask=0;mask<(1<<12);mask++){
        int sum=0;
        for(int i=0;i<12;i++){
            if(mask & (1<<i)){//i 番目の紙幣を選んでるかどうか
                sum += a[i];
            }
        }
        if(sum == 500) count ++;
    }
    printf("%d\n",count);
    return 0;
}