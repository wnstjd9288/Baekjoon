#include <stdio.h>
#include <stdlib.h>

int map[1001][1001] = { 0, };
int visited_D[1001] = { 0, };
int visited_B[1001] = { 0, };
int que[1001] = { 0, };
int n, m;
void DFS(int r) {
    printf("%d ", r);
    visited_D[r] = 1;
    for (int i = 1; i <= n; i++) {
        if (map[r][i] == 1) {
            if (!visited_D[i]) DFS(i);
        }
    }
}
void BFS(int r) {
    int h = -1, t = -1;
    printf("%d ", r);
    visited_B[r] = 1;
    que[++t] = r;

    while (h != t) {
        int pop = que[++h];
        for (int i = 1; i <= n; i++) {
            if (map[pop][i] && !visited_B[i]) {
                printf("%d ", i);
                que[++t] = i;
                visited_B[i] = 1;
            }
        }
    }

}
int main() {

    int r;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        map[s][e] = map[e][s] = 1;
    }
    DFS(r); puts(""); BFS(r);
    return 0;
}