#include <stdio.h>
#include <stdlib.h>

typedef struct Cod {
    int x;
    int y;
}Cod;

int map[51][51];
int n, m;
Cod xy[4] = { {0,-1},{-1,0},{0,1},{1,0} };

int main() {
    int x, y, dir;
    int cnt = 0;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &dir);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    while (1) {
        if (map[x][y] == 1) break;
        if (!map[x][y]) { map[x][y] = 2; cnt++; }
        int i;
        for (i = 0; i < 4; i++) {
            int ndir = dir - i;
            if (ndir < 0)ndir += 4;
            Cod next = { x + xy[ndir].x,y + xy[ndir].y };
            if (!map[next.x][next.y]) {
                x = next.x;
                y = next.y;
                dir = (ndir + 3) % 4;
                break;
            }
        }
        if (i == 4) {
            x += xy[(dir + 3) % 4].x;
            y += xy[(dir + 3) % 4].y;
        }
    }
    printf("%d", cnt);
    return 0;
}