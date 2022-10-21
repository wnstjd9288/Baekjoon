#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
    int jump;
}Cod;
int k;
int n, m;
int min = 2e9;
int map[201][201] = { 0, };
int visited[201][201][31] = {0,};
Cod que[10000001];
Cod xy[12] = { {0,1},{1,0},{0,-1},{-1,0},{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1} };
int BFS(Cod start) {
    int h = -1, t = -1;
    visited[start.x][start.y][0] = 1;
    que[++t] = start;

    while (h != t) {
        Cod now = que[++h];
        for (int i = 0; i < 12; i++) {
            if (now.jump == k && i >= 4) break;
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (i >= 4) next.jump++;
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
            if (map[next.x][next.y]) continue;
            if (visited[next.x][next.y][next.jump] && visited[next.x][next.y][next.jump] <= visited[now.x][now.y][now.jump] + 1) continue;
            if (next.x == m - 1 && next.y == n - 1) return visited[now.x][now.y][now.jump];
            visited[next.x][next.y][next.jump] = visited[now.x][now.y][now.jump] + 1;
            que[++t] = next;
        }
    }
    return -1;
}

int main() {
    scanf("%d", &k);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    if (n * m == 1) printf("0");
    else printf("%d", BFS({ 0,0,0 }));


    return 0;
}