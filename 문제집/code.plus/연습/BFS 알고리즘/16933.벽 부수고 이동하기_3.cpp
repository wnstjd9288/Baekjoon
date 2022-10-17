#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
    int wall;
    int day;
}Cod;
int n, m, k;
int map[1001][1001];
int visited[1001][1001][11][2] = { 0, };
Cod que[20000001]; // 큐 공간을 충분히 둘것.
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
int BFS(Cod start) {
    int t = -1, h = -1;
    que[++t] = start;
    visited[start.x][start.y][start.wall][start.day] = 1;
    while (h != t) {
        Cod now = que[++h];
        if (now.x == n - 1 && now.y == m - 1) return visited[now.x][now.y][now.wall][now.day];
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            next.day = 1 - now.day;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
            if (map[next.x][next.y]) {
                if (now.wall == k) continue;
                else {
                    if (now.day) next.wall++;
                    else {
                        if (visited[now.x][now.y][now.wall][1 - now.day]) continue;
                        visited[now.x][now.y][now.wall][1 - now.day] = visited[now.x][now.y][now.wall][now.day] + 1;
                        que[++t] = { now.x,now.y,now.wall,1 - now.day };
                        continue;
                    }
                }
            }
            if (visited[next.x][next.y][next.wall][next.day]) continue;
            visited[next.x][next.y][next.wall][next.day] = visited[now.x][now.y][now.wall][now.day] + 1;
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
    printf("%d", BFS({ 0,0,0,1 }));
    return 0;
}