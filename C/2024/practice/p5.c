// 5 E.txt
// 各行に整数 ai が1つずつ 合計1000個 0<=ai<=1000
// 空スタック S を用意し 順に読む
// ai>0 なら push(ai)
// ai=0 なら pop する その時スタックは空でないと仮定してよい
// 全部読み終えたあと スタックに残っている整数の総和を出力する

#include<stdio.h>

long long st[1005];

int top = 0;

// スタックに値を積む
void push(long long x){
    st[top++] = x;
}

// スタックから値を取り出す
long long pop(void){
    return st[--top];
}


int main(void){
    long long a;

    for(int i=0;i<1000;i++){
        scanf("%lld",&a);
        if(a == 0){
            pop();
        }else{
            push(a);
        }
    }

    long long sum=0;
    for(int i=0;i<top;i++) sum += st[i];
    printf("%lld\n", sum);
    return 0;
}