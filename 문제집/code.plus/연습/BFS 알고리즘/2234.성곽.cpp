#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
}Cod;
int n, m;
int map[51][51];
int visited[51][51] = { 0, };
int size[2502] = { 0, };
int cnt = 0;
int ans = -1;
Cod que[10000001];
Cod xy[4] = { {0,-1},{-1,0},{0,1},{1,0} };

int BFS(Cod start) {
    int h = -1, t = -1;
    int count = 0;
    que[++t] = start;
    visited[start.x][start.y] = cnt;
    while (h != t) {
        Cod now = que[++h];
        count++;
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
            if (map[now.x][now.y] & (1 << i)) continue;
            if (visited[next.x][next.y]) continue;
            visited[next.x][next.y] = cnt;
            que[++t] = next;
        }
    }
    return count;
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                cnt++;
                size[cnt] = BFS({ i,j });
                if (size[cnt] > ans) ans = size[cnt];
            }
        }
    }
    printf("%d\n%d\n", cnt, ans);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Cod now = { i,j };
            for (int k = 0; k < 4; k++) {
                Cod next = now;
                next.x += xy[k].x;
                next.y += xy[k].y;
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
                if (visited[next.x][next.y] != visited[now.x][now.y]) {
                    if (ans < size[visited[next.x][next.y]] + size[visited[now.x][now.y]]) {
                        ans = size[visited[next.x][next.y]] + size[visited[now.x][now.y]];
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}