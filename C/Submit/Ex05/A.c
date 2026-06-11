#include <stdio.h>

int n, a[20];

int solve(int i, int m) {
    if (m == 0) return 1;
    if (i >= n) return 0;
    
    //各要素を使うか使わないかの全パターンを再帰でゴリ押しして、一つでも作れたら勝ちということ
    int res = solve(i + 1, m) || solve(i + 1, m - a[i]);
    return res;
}

int main() {
    int q, m;

    if (scanf("%d", &n) == EOF) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &m);
        if (solve(0, m)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}