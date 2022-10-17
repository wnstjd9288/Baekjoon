#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
    int value;
    int wall;
}Cod;
int n, m, k;
int map[1001][1001];
int visited[1001][1001][11] = { 0, };
Cod que[11000001];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
int BFS(Cod start) {
    int t = -1, h = -1;
    que[++t] = start;
    while (h != t) {
        Cod now = que[++h];
        if (now.x == n - 1 && now.y == m - 1) return now.value;
        if (visited[now.x][now.y][now.wall]) continue;
        visited[now.x][now.y][now.wall] = now.value;
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            next.value++;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
            if (map[next.x][next.y]) {
                if (now.wall == k) continue;
                else next.wall++;
            }
            if (visited[next.x][next.y][next.wall]) continue;
            que[++t] = next;
        }
    }
    return -1;
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    printf("%d", BFS({ 0,0,1,0 }));
    return 0;
}