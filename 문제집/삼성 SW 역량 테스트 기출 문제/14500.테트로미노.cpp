#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Cod {
    int x;
    int y;
}Cod;

int n, m;
int max = -1;
int map[501][501];
int visited[501][501] = { 0, };
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
void DFS(Cod now, int cnt, int sum) {
    if (cnt == 3) {
        sum += map[now.x][now.y];
        if (sum > max)max = sum;
        return;
    }
    visited[now.x][now.y] = 1;
    for (int i = 0; i < 4; i++) {
        Cod next = now;
        next.x += xy[i].x;
        next.y += xy[i].y;
        if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
        if (visited[next.x][next.y]) continue;
        DFS(next, cnt + 1, sum + map[now.x][now.y]);
    }
    visited[now.x][now.y] = 0;
}

int main() {
    Cod tetra5[4] = { {0,0},{0,1},{1,1},{0,2} };
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            DFS({ i,j }, 0, 0);
            int sum = 0;
            for (int k = 0; k < 4; k++) {
                Cod next = { i,j };
                next.x += tetra5[k].x;
                next.y += tetra5[k].y;
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) { sum -= 999999; continue; }
                sum += map[next.x][next.y];
            }
            if (sum > max)max = sum; 
            sum = 0;
            for (int k = 0; k < 4; k++) {
                Cod next = { i,j };
                next.x -= tetra5[k].x;
                next.y += tetra5[k].y;
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) { sum -= 999999; continue; }
                sum += map[next.x][next.y];
            }
            if (sum > max)max = sum;
            sum = 0;
            for (int k = 0; k < 4; k++) {
                Cod next = { i,j };
                next.x += tetra5[k].y;
                next.y += tetra5[k].x;
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) { sum -= 999999; continue; }
                sum += map[next.x][next.y];
            }
            if (sum > max)max = sum;
            sum = 0;
            for (int k = 0; k < 4; k++) {
                Cod next = { i,j };
                next.x += tetra5[k].y;
                next.y -= tetra5[k].x;
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) { sum -= 999999; continue; }
                sum += map[next.x][next.y];
            }
            if (sum > max)max = sum;
        }
    }
    printf("%d", max);
    return 0;
}