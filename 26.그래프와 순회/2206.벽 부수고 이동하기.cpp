#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int x;
    int y;
    int block;
}cod;

cod que[10000001] = { 0, };
cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
int visited[1001][1001][2] = {0,};
int map[1001][1001] = {0,};
int res = 999999;
int main() {

    int n, m;
    int h = -1, t = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 0) map[i][j] = 1;
            else if (map[i][j] == 1) map[i][j] = 0;
        }
    }
    que[++t].x = 0;
    que[t].y = 0;
    que[t].block = 0;
    while (h != t) {
        cod now = que[++h];
        if (now.x == n - 1 && now.y == m - 1) {
            if (visited[now.x][now.y][now.block] < res) res = visited[now.x][now.y][now.block];
            break;
        }
        for (int i = 0; i < 4; i++) {
            cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
            if (map[next.x][next.y] == 0 && next.block == 0) {
                visited[next.x][next.y][1] = visited[now.x][now.y][0] + 1;
                next.block = 1;
                que[++t] = next;
                continue;
            }
            if (map[next.x][next.y] == 0) continue;
            if (!visited[next.x][next.y][next.block] || visited[next.x][next.y][next.block] > visited[now.x][now.y][now.block] + 1) {
                visited[next.x][next.y][next.block] = visited[now.x][now.y][now.block] + 1;
                que[++t] = next;
            }
        }
    }
    if (res == 999999) printf("-1");
    else printf("%d", res+1);
    return 0;
}