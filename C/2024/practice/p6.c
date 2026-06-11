// 6 F.txt
// 1行目に互いに異なる整数 ai が1000000個 0<=ai<=1e9 これを配列Aとする
// 2行目に互いに異なる整数 bi が1000000個 0<=bi<=1e9 これを配列Bとする
// AとBの両方に含まれる整数の個数を出力する

#include <stdio.h>

#define MAX 1000005
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int A[MAX];
int B[MAX];

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n=1000000;
    int i=0;
    int j=0;
    int count=0;;
    for (i = 0; i < n; i++) scanf("%d", &A[i]);
    for (j=0;j<n;j++) scanf("%d",&B[j]);

    mergeSort(A, 0, n);
    mergeSort(B, 0, n);

    i = 0;
    j = 0;

    while(i < n && j < n){//二つを比べながらカウント
        if(A[i] == B[j]){
            count++;
            i++;
            j++;
        }else if(A[i] < B[j]){
            i++;
        }else{
            j++;
        }
    }

    printf("%d\n", count);

    return 0;
}