#include <stdio.h>
#include <stdlib.h>

int map[1001][1001] = { 0, };
int visited_D[1001] = { 0, };
int visited_B[1001] = { 0, };
int que[1001] = { 0, };
int n, m;
int cnt = 0;
void DFS(int r) {
    visited_D[r] = ++cnt;
    for (int i = 1; i <= n; i++) {
        if (map[r][i] == 1) {
            if (!visited_D[i]) DFS(i);
        }
    }
}
int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        map[s][e] = map[e][s] = 1;
    }
    DFS(1);
    printf("%d", cnt - 1);
    return 0;
}