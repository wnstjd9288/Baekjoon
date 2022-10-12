#include <stdio.h>
#include <stdlib.h>
int n, m;
int visited[51][51] = { 0, };
int map[51][51] = { 0, };
int xx[4] = { 0,1,0,-1 }, yy[4] = { 1,0,-1,0 };

void DFS(int x, int y, int cnt) {
    visited[x][y] = 1;
    map[x][y] = cnt;
    for (int i = 0; i < 4; i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
        if (!visited[nx][ny] && map[nx][ny] == 1) DFS(nx, ny, cnt);
    }
}

int main() {

    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++) {
        int k;
        int cnt = 2;
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = map[i][j] = 0;
            }
        }
        for (int i = 0; i < k; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            map[b][a] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1) {
                    DFS(i, j, cnt);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt - 2);
    }

    return 0;
}