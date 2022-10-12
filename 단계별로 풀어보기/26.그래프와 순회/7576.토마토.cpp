#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int x;
    int y;
}cod;

int n, m;
int h = -1, t = -1;
int visited[1001][1001] = { 0, };
int map[1001][1001] = { 0, };
cod que[1000001] = { 0, };
cod xy[4] = { {1,0},{0,1},{-1,0},{0,-1} };
void BFS() {

    while (h != t) {
        cod now = que[++h];
        for (int i = 0; i < 4; i++) {
            cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
            if (map[next.x][next.y] == -1)continue;
            if (!visited[next.x][next.y] || visited[next.x][next.y] > visited[now.x][now.y] + 1) {
                visited[next.x][next.y] = visited[now.x][now.y] + 1;
                que[++t] = next;
            }
        }
    }

}

int main() {

    int max = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                visited[i][j] = 1;
                que[++t].x = i;
                que[t].y = j;
            }
        }
    }
    BFS();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != -1 && visited[i][j] == 0) {
                printf("-1");
                exit(0);
            }
            if (visited[i][j] > max)max = visited[i][j];
        }
    }
    printf("%d", max - 1);
    return 0;
}