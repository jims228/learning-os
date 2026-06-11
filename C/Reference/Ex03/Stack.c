//逆ポーランド記法の問題
//スタックは 後に入れたものが先に出る という箱
//1 2 + は3になる
//左から入力を読み込む
//数字ならスタックに積む
//演算子ならスタックから取り出して計算して結果をまた積む
//最後に残った一個が答えになる
#include<stdio.h>

// スタックとして使う配列
// この問題はオペランド数が最大100なので余裕を見て200にしておく
long long st[200];

// スタックの要素数を表す
// top は 次に push する位置 でもある
int top = 0;

// スタックに値を積む
void push(long long x){
    // st[top] に入れてから top を1増やす
    st[top++] = x;
}

// スタックから値を取り出す
long long pop(void){
    // top を1減らして その位置の値を返す
    // 例 top=3 なら 有効な要素は st[0],st[1],st[2]
    // pop すると top=2 になり st[2] を返す
    return st[--top];
}

// 文字列を long long に変換する
long long parse_ll(const char *s){
    long long sign = 1;  // 符号
    int i = 0;           // 文字列の位置

    // 先頭が - なら負数
    if(s[i] == '-'){
        sign = -1;
        i++;
    }

    // 10進数として数値化
    // "123" -> ((0*10+1)*10+2)*10+3
    long long x = 0;
    while(s[i] != '\0'){
        x = x * 10 + (s[i] - '0');  // '0' を引いて 0-9 にする
        i++;
    }

    return sign * x;
}

int main(void){
    char s[32];  // トークンを1個読むための配列

    // 入力は 1行だが スペース区切りで複数トークンなので
    // scanf を EOF まで回して全トークンを読む
    while(scanf("%31s", s) == 1){

        // 演算子かどうか判定
        // 演算子は "+", "-", "*" の1文字だけ
        // s[1]=='\0' で 1文字かどうか確認しておく
        if(s[1] == '\0' && (s[0] == '+' || s[0] == '-' || s[0] == '*')){

            // 逆ポーランド記法では
            // 演算子が来たら スタックの上から2つ取り出して計算する
            // 取り出し順が重要
            // a b - は a-b なので 先に b を pop 次に a を pop
            long long b = pop();
            long long a = pop();

            // 計算結果をスタックに戻す
            if(s[0] == '+') push(a + b);
            else if(s[0] == '-') push(a - b);
            else push(a * b);

        }else{
            // 演算子でないなら数字
            // 文字列を long long に変換して push
            push(parse_ll(s));
        }
    }

    // 最後にスタックに残る1個が計算結果
    printf("%lld\n", pop());

    return 0;
}
