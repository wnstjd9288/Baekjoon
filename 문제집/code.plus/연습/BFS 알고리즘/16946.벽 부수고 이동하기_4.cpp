#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
}Cod;

int n, m;
int cnt = 0;
int map[1002][1002] = { 0, };
int box[10000001] = { 0, };
int res[1002][1002] = { 0, };
int visited[1002][1002] = { 0, };
int check[10000001] = { 0, };
Cod que[20000001];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };

int BFS(Cod start, int k) {
    int h = -1, t = -1;
    int c = 0;

    que[++t] = start;
    map[start.x][start.y] = k;
    visited[start.x][start.y] = 1;
    c++;
    while (h != t) {
        Cod now = que[++h];
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;

            if (next.x <= 0 || next.x > n || next.y <= 0 || next.y > m) continue;
            if (map[next.x][next.y])continue;
            if (visited[next.x][next.y])continue;

            visited[next.x][next.y] = 1;
            map[next.x][next.y] = k;
            c++;
            que[++t] = next;
        }
    }
    return c;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j]) map[i][j] *= -1;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!map[i][j]) {
                cnt++;
                box[cnt] = BFS({ i,j }, cnt);
            }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == -1) {
                res[i][j] = 1;
                for (int k = 0; k < 4; k++) {
                    if (map[i + xy[k].x][j + xy[k].y] > 0 && !check[map[i + xy[k].x][j + xy[k].y]]) {
                        res[i][j] += box[map[i + xy[k].x][j + xy[k].y]];
                        check[map[i + xy[k].x][j + xy[k].y]] = 1;
                    }
                }
                for (int k = 0; k < 4; k++) check[map[i + xy[k].x][j + xy[k].y]] = 0;
            }
            printf("%d", res[i][j] ? res[i][j] % 10 : 0);
        }puts("");
    }
    return 0;
}