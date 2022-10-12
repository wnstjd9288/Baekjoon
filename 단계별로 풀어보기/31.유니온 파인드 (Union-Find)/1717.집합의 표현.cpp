#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int data;
    int rank = 0;
}Set;

Set set[1000001];

int find(int x) {
    if (set[x].data == x) return x;
    else return set[x].data = find(set[x].data);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (set[x].rank < set[y].rank) set[x].data = y;
    else {
        set[y].data = x;

        if (set[x].rank == set[y].rank) set[x].rank++;
    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) set[i].data = i;

    for (int j = 0; j <= m; j++) {
        int a, b, k;
        scanf("%d %d %d", &k, &a, &b);
        if (!k) {
            union_set(a, b);
        }
        else {
            if (find(a) == find(b)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}