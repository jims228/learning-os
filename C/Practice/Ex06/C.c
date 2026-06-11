#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char ch;
    int  n;
    int  x;   // 入力順
}C;

// 関数プロトタイプ
void ex(C *a, C *b);
int  part(C A[],int p,int r);
void quicksort(C A[],int p,int r);
int  s(C a[],int n);

int main(){
    int n;
    scanf("%d",&n);

    C c[n];

    // 入力
    for (int i=0;i<n;i++){
        scanf(" %c %d",&c[i].ch,&c[i].n);
        c[i].x=i;   // 入力順を保持
    }

    // クイックソート
    quicksort(c,0,n-1);

    // 安定判定
    if (s(c,n)) printf("Stable\n");
    else    printf("Not stable\n");

    // 出力
    for (int i=0;i<n;i++){
        printf("%c %d\n",c[i].ch,c[i].n);
    }
    return 0;
}

// 交換
void ex(C*a, C*b){
    C t=*a;
    *a=*b;
    *b=t;
}

// partition
int part(C A[],int p,int r){
    C x=A[r];
    int i=p-1;

    for (int j=p;j<r;j++)
    {
        if (A[j].n <= x.n)
        {
            i++;
            ex(&A[i],&A[j]);
        }
    }

    ex(&A[i+1],&A[r]);
    return i+1;
}

// 小さい方だけ再帰してスタック節約
void quicksort(C A[],int p,int r)
{
    while (p < r)
    {
        int q=part(A,p,r);

        if (q-p < r-q)
        {
            quicksort(A,p,q-1);
            p=q+1;
        }
        else
        {
            quicksort(A,q+1,r);
            r=q-1;
        }
    }
}

// 同値のとき入力順(x)が崩れてたらNot stable
int s(C a[], int n)
{
    for (int i=0;i<n-1;i++)
    {
        if (a[i].n == a[i+1].n && a[i].x > a[i+1].x)
        {
            return 0;
        }
    }
    return 1;
}
