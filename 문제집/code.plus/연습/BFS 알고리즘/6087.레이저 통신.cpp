#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
    int curve;
    int dir;
}Cod;

int n,m;
int min = 2e9;
char map[101][101];
int visited[101][101] = { 0, };
Cod que[1000001];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };

int BFS(Cod start) {
    int h = -1, t = -1;
    que[++t] = start;
    visited[start.x][start.y] = 1;
    while (h != t) {
        Cod now = que[++h];
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (i != now.dir) {
                next.dir = i;
                next.curve++;
            }
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
            if (map[next.x][next.y] == '*') continue;
            if (visited[next.x][next.y] && visited[next.x][next.y] < next.curve) continue;
            if (map[next.x][next.y] == 'C') {
                if (min > next.curve) min = next.curve;
                continue;
            }
            visited[next.x][next.y] = next.curve;
            que[++t] = next;
        }
    }
    return min;
}

int main() {
    Cod start;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'C') start = { i,j,0,-1 };
        }
    }
    map[start.x][start.y] = '.';
    printf("%d\n", BFS(start) - 1);
    return 0;
}