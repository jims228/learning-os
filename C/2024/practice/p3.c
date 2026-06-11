// 3 C.txt
// 空白区切りで整数が1000001個並ぶ 0<=ai<=1e9
// 昇順に並べたとき真ん中に来る値 中央値 を出力する

#include <stdio.h>

#define MAX 1000005
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int A[MAX];

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
    int n=1000001;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    mergeSort(A, 0, n);

    printf("%d\n", A[n/2]);

    return 0;
}