// 9 I.txt
// 1行目に文字列S1 2行目に文字列S2 が与えられる
// 英小文字のみ 長さは100以下
// S1とS2の最長共通部分列 LCS の長さを出力する
//
// 方針 DP
// dp[i][j] を
// S1の先頭i文字 と S2の先頭j文字 の LCSの長さ とする
//
// 初期化
// dp[0][*]=0 dp[*][0]=0
// どちらかが空文字なら共通部分列は長さ0
//
// 遷移
// s1[i-1] と s2[j-1] を比較する
// 同じなら dp[i][j]=dp[i-1][j-1]+1
// 違うなら dp[i][j]=max(dp[i-1][j], dp[i][j-1])
//
// 答え
// dp[n][m]
//
// 計算量
// O(n*m) ここでは最大 100*100 なので余裕

#include <stdio.h>
#include <string.h>

#define MAXL 105

// 2つの整数の大きい方を返す
int max2(int a, int b){
    return (a > b) ? a : b;//a>bが真ならa、偽ならb
}

int main(void){
    char s1[MAXL], s2[MAXL];

    // 文字列を2本読む
    scanf("%s", s1);
    scanf("%s", s2);

    int n = (int)strlen(s1);
    int m = (int)strlen(s2);

    // dp[i][j] = S1の先頭i文字 と S2の先頭j文字 の LCS長
    // static にしておくとスタックを使わず安全
    static int dp[MAXL][MAXL];

    // 初期化 dp[0][*], dp[*][0] は0
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    // DPを埋める
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                // 末尾の文字が同じなら その文字を採用できる
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                // 末尾が違うなら S1側を捨てるか S2側を捨てるかの良い方
                dp[i][j] = max2(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // 答え
    printf("%d\n", dp[n][m]);
    return 0;
}
