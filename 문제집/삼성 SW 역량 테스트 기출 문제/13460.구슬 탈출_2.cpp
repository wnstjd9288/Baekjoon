#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Cod {
    int x;
    int y;
}Cod;

typedef struct grid {
    Cod red;
    Cod blue;
    int cnt;
}grid;

int n, m;
int min = 99;
grid que[100001];
Cod visited[11][11] = { 0, };
Cod destination;
char map[11][11];
char map_int[11][11] = { 0, };

void BFS(Cod Red, Cod Blue) {

    Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
    int h = -1, t = -1;
    que[++t] = { Red,Blue,1 };
    visited[Red.x][Red.y].x = 1;
    visited[Blue.x][Blue.y].y = 1;

    while (h != t) {
        grid now = que[++h];
        if (now.cnt >= 11 || now.cnt >= min) continue;
        for (int i = 0; i < 4; i++) {
            grid next = now;
            while (1) {
                next.red.x += xy[i].x;
                next.red.y += xy[i].y;
                if (map[next.red.x][next.red.y] == '#' || next.red.x == next.blue.x && next.red.y == next.blue.y) {
                    next.red.x -= xy[i].x;
                    next.red.y -= xy[i].y;
                    break;
                }
                if (map[next.red.x][next.red.y] == 'O') {
                    next.red.x = -1;
                    next.red.y = -1;
                    break;
                }
            }
            while (1) {
                next.blue.x += xy[i].x;
                next.blue.y += xy[i].y;
                if (map[next.blue.x][next.blue.y] == '#' || next.red.x == next.blue.x && next.red.y == next.blue.y) {
                    next.blue.x -= xy[i].x;
                    next.blue.y -= xy[i].y;
                    break;
                }
                if (map[next.blue.x][next.blue.y] == 'O') {
                    next.blue.x = -1;
                    next.blue.y = -1;
                    break;
                }
            }
            if (next.blue.x == -1) continue;
            if (next.red.x == -1) {
                if (now.cnt + 1 < min)min = now.cnt + 1;
                continue;
            }
            while (1) {
                next.red.x += xy[i].x;
                next.red.y += xy[i].y;
                if (map[next.red.x][next.red.y] == '#' || next.red.x == next.blue.x && next.red.y == next.blue.y) {
                    next.red.x -= xy[i].x;
                    next.red.y -= xy[i].y;
                    break;
                }
                if (map[next.red.x][next.red.y] == 'O') {
                    next.red.x = -1;
                    next.red.y = -1;
                    break;
                }
            }
            while (1) {
                next.blue.x += xy[i].x;
                next.blue.y += xy[i].y;
                if (map[next.blue.x][next.blue.y] == '#' || next.red.x == next.blue.x && next.red.y == next.blue.y) {
                    next.blue.x -= xy[i].x;
                    next.blue.y -= xy[i].y;
                    break;
                }
                if (map[next.blue.x][next.blue.y] == 'O') {
                    next.blue.x = -1;
                    next.blue.y = -1;
                    break;
                }
            }
            if (next.blue.x == -1) continue;
            if (next.red.x == -1) {
                if (now.cnt + 1 < min)min = now.cnt + 1;
                continue;
            }
            if (next.red.x == now.red.x && next.red.y == now.red.y && next.blue.x == now.blue.x && next.blue.y == now.blue.y) continue;

            visited[next.red.x][next.red.y].x = now.cnt + 1;
            visited[next.blue.x][next.blue.y].y = now.cnt + 1;
            next.cnt = now.cnt + 1;
            que[++t] = next;
        }
    }
}

int main() {
    Cod R, B;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%*c");
        for (int j = 0; j < m; j++) {
            scanf("%1c", &map[i][j]);
            if (map[i][j] == '#') map_int[i][j] = -1;
            switch (map[i][j]) {
            case 'O':
                destination = { i,j };
                break;
            case 'R':
                R = { i,j };
                break;
            case 'B':
                B = { i,j };
                break;
            }
        }
    }
    BFS(R, B);
    if (min == 99) printf("-1");
    else printf("%d", min-1);

    return 0;
}