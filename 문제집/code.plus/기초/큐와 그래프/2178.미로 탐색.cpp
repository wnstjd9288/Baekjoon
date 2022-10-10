#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int x;
    int y;
}cod;

int n, m;
int visited[101][101] = { 0, };
int map[101][101] = { 0, };
cod que[10001] = { 0, };
cod xy[4] = { {1,0},{0,1},{-1,0},{0,-1} };
void BFS(cod c) {
    int h = -1, t = -1;
    visited[c.x][c.y] = 1;
    que[++t] = c;
    while (h != t) {
        cod now = que[++h];
        for (int i = 0; i < 4; i++) {
            cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
            if (!visited[next.x][next.y] && map[next.x][next.y]) {
                visited[next.x][next.y] = visited[now.x][now.y] + 1;
                que[++t] = next;
            }
        }
    }

}

int main() {

    cod c = { 0,0 };
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    BFS(c);
    printf("%d", visited[n - 1][m - 1]);
    return 0;
}