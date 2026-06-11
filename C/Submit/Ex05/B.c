#include <stdio.h>

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt = 0;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    
    int i = 0, j = 0;
    //番兵を置いておくことで、左右どちらかの配列が空になった時の複雑な条件分岐をスルーできる
    for (int k = left; k < right; k++) {
        cnt++;
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
    int n, A[MAX];

    if (scanf("%d", &n) == EOF) return 0;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    mergeSort(A, 0, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", A[i], (i == n - 1 ? "" : " "));
    }
    printf("\n%d\n", cnt);

    return 0;
}