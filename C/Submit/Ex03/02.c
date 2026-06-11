#include <stdio.h>

typedef struct {
    char name[100];
    int time;
} P;
#define LEN 100005

P Q[LEN];
int head = 0;
int tail = 0;

void enqueue(P x) {
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

P dequeue() {
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int elaps = 0;
    int c;
    int i, q, n;
    P u;

    scanf("%d %d", &n, &q);

    for (i = 0; i < n; i++) {
        scanf("%s %d", u.name, &u.time);
        enqueue(u);
    }

    while (head != tail) {
        u = dequeue();

        c = min(q, u.time);
        
        u.time -= c;
        elaps += c;
        if (u.time > 0) {
            enqueue(u);
        }
        else {
            printf("%s %d\n", u.name, elaps);
        }
    }

    return 0;
}