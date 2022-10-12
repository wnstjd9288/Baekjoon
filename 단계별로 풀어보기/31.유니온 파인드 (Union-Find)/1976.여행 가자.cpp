#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int data;
    int rank = 0;
}Set;

Set set[10001];

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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            scanf("%d", &a);
            if (a) union_set(i, j);
        }
    }

    bool flag = true;
    int a;
    scanf("%d", &a);
    int check = find(a);
    for (int j = 1; j < m; j++) {
        scanf("%d", &a);
        if (find(a) != check) { flag = false; break; }
    }
    if (flag) printf("YES");
    else printf("NO");
    return 0;
}