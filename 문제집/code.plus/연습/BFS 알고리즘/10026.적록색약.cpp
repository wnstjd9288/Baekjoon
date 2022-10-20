#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
}Cod;
int n;
int visited[101][101] = { 0, };
Cod que[1000001];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
void BFS(Cod start,int map[][101]) {
    int h = -1, t = -1;
    visited[start.x][start.y] = map[start.x][start.y];
    que[++t] = start;
    while (h != t) {
        Cod now = que[++h];
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.x >= n) continue;
            if (visited[next.x][next.y]) continue;
            if (visited[now.x][now.y] != map[next.x][next.y]) continue;
            visited[next.x][next.y] = visited[now.x][now.y];
            que[++t] = next;
        }
    }
}

int main() {

    char map[101][101];
    int map_normal[101][101];
    int map_RB[101][101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'R') map_normal[i][j] = map_RB[i][j] = 1;
            if (map[i][j] == 'G') {
                map_normal[i][j] = 2;
                map_RB[i][j] = 1;
            }
            if (map[i][j] == 'B') {
                map_RB[i][j] = 2;
                map_normal[i][j] = 3;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j]) {
                BFS({ i,j }, map_normal);
                cnt++;
            }
    printf("%d", cnt);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) visited[i][j] = 0;
    cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j]) {
                BFS({ i,j }, map_RB);
                cnt++;
            }
    printf(" %d", cnt);
    return 0;
}