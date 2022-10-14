#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
}Cod;
char map[51][51];
int color[51][51] = { 0, };
int n;
int max = 0;
bool flag = false;
Cod xy[6] = { {0,1},{1,0},{0,-1},{-1,0},{1,-1},{-1,1} };

void DFS(Cod now,int c) {
    color[now.x][now.y] = c;
    for (int i = 0; i < 6; i++) {
        Cod next = { now.x + xy[i].x,now.y + xy[i].y };
        if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) continue;
        if (map[next.x][next.y] == 'X' && color[next.x][next.y] == c) {
            flag = true;
            return;
        }
        if (map[next.x][next.y] == 'X' && !color[next.x][next.y]) DFS(next, c * -1);
        if (flag) return;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'X' && !color[i][j]) DFS({ i,j }, 1);
            if (color[i][j] == -1)max = 2;
            if (color[i][j] > max)max = color[i][j];
            if (flag) break;
        }
        if (flag) break;
    }
    if (flag) printf("3");
    else printf("%d", max);
    return 0;
}