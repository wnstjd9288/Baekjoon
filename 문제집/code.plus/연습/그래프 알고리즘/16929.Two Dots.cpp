#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Cod {
    int x;
    int y;
}Cod;
char map[51][51] = { 0, };
int visited[51][51] = { 0, };
int n, m;
bool flag = false;
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
void DFS(Cod now, Cod prev) {
    if (flag) return;
    visited[now.x][now.y] = 1;
    for (int i = 0; i < 4; i++) {
        Cod next = now;
        next.x += xy[i].x;
        next.y += xy[i].y;
        if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
        if (next.x == prev.x && next.y == prev.y) continue;
        if (map[next.x][next.y] == map[now.x][now.y]) {
            if (visited[next.x][next.y]) { 
                flag = true;
                return;
            }
            else DFS(next, now);
        }
    }
}

bool Two_Dots() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            DFS({ i,j }, { -1,-1 });
            if (flag) return true;
        }
    }
    return false;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", map[i]);
    if (Two_Dots()) printf("Yes");
    else printf("No");
    return 0;
}