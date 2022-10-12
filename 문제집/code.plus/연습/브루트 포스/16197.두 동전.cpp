#include <stdio.h>
#include <stdlib.h>

typedef struct Cod {
    int x;
    int y;
}Cod;

typedef struct Ball {
    Cod b1;
    Cod b2;
    int move = 0;
}Ball;

int n, m;
char map[21][21];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
Cod visited[21][21] = { 0, };
Ball que[1000001];

int BFS(Ball start) {

    int h = -1, t = -1;
    que[++t] = start;
    while (h != t) {
        Ball now = que[++h];
        if (visited[now.b1.x][now.b2.y].x && visited[now.b1.x][now.b2.y].x == visited[now.b2.x][now.b2.y].y) continue;
        visited[now.b1.x][now.b1.y].x = visited[now.b2.x][now.b2.y].y = h + 1;
        if (now.move >= 10) continue;
        for (int i = 0; i < 4; i++) {
            Ball next = now;
            next.b1.x += xy[i].x;
            next.b1.y += xy[i].y;
            next.b2.x += xy[i].x;
            next.b2.y += xy[i].y;
            next.move++;
            int cnt = 0;
            if (next.b1.x < 0 || next.b1.x >= n || next.b1.y < 0 || next.b1.y >= m) cnt++;
            if (next.b2.x < 0 || next.b2.x >= n || next.b2.y < 0 || next.b2.y >= m) cnt++;
            if (cnt == 2) continue;
            else if (cnt == 1) { 
                return next.move; 
            }
            if (map[next.b1.x][next.b1.y] == '#') next.b1 = now.b1;
            if (map[next.b2.x][next.b2.y] == '#') next.b2 = now.b2;
            if (next.b1.x == now.b1.x && next.b1.y == now.b1.y && next.b2.x == now.b2.x && next.b2.y == now.b2.y) continue;
            que[++t] = next;
        }
    }
    return -1;
}

int main() {
    int cnt = 0;
    Cod start[2];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%*c");
        for (int j = 0; j < m; j++) {
            scanf("%c", &map[i][j]);
            if (map[i][j] == 'o') start[cnt++] = { i,j };
        }
    }
    printf("%d", BFS({ start[0],start[1],0 }));

    return 0;
}