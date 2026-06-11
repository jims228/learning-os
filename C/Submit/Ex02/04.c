#include<stdio.h>

int N,cnt,m,G[50];

void insertionSort(int A[], int n, int g){
    int i,j,v;
    for(i=g;i<n;i++){
        v=A[i];
        j=i-g;
        while(j>=0 && A[j]>v){
            A[j+g] = A[j];
            j=j-g;
            cnt++;
        }
        A[j+g]=v;
    }
}

void shellSort(int A[],int n){
    int i;
    cnt=0;
    m=0;
    int h=1;
    
    int temp_G[50];
    int temp_m = 0;
    for(i = 0; h <= n; i++) {
        G[i] = h;
        h = h*3 + 1; 
        m++; 
        if (m >= 50) break;
    }
    
    for(i = m - 1; i >= 0; i--){
        insertionSort(A, n, G[i]);
    }
}

void printArray(int A[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\n",A[i]);
    }
}

int main(){
    int i;
    int A[1000001];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    shellSort(A,N);
    printf("%d\n",m);
    for(i=m-1; i>=0; i--){
        printf("%d", G[i]);
        if(i) printf(" "); // 最後の要素以外に空白★
    }
    printf("\n");
    printf("%d\n",cnt);
    printArray(A,N);

    return 0;
}