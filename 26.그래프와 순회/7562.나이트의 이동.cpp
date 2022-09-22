#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int x;
    int y;
}cod;

int n;
int visited[301][301] = { 0, };
cod que[100001] = { 0, };
cod xy[8] = { {2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1} };
void BFS(cod c) {
    int h = -1, t = -1;
    visited[c.x][c.y] = 1;
    que[++t] = c;
    while (h != t) {
        cod now = que[++h];
        for (int i = 0; i < 8; i++) {
            cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) continue;
            if (!visited[next.x][next.y]) {
                visited[next.x][next.y] = visited[now.x][now.y] + 1;
                que[++t] = next;
            }
        }
    }

}

int main() {
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++) {
        cod c;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) visited[i][j] = 0;
        scanf("%d %d", &c.x, &c.y);
        BFS(c);
        scanf("%d %d", &c.x, &c.y);
        printf("%d\n", visited[c.x][c.y] - 1);
    }

    return 0;
}