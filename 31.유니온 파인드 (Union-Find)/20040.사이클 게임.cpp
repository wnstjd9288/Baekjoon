#include <stdio.h>
#include <stdlib.h>
typedef struct grid {
    int data;
    int rank = 0;

}Set;

Set set[500001];

int find(int x) {
    if (set[x].data == x) return x;
    else return set[x].data = find(set[x].data);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (set[x].rank < set[y].rank) {
        set[x].data = y; 
    }
    else {
        set[y].data = x;

        if (set[x].rank == set[y].rank) set[x].rank++;
    }
}

int main() {

    int n, m;
    int cnt = 0;
    int i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) { 
        set[i].data = i; 
        set[i].rank = 0;
    }
    for (i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (find(a) == find(b)) break;
        union_set(a, b);
    }
    if (i == m + 1) printf("0");
    else printf("%d", i);
    return 0;
}