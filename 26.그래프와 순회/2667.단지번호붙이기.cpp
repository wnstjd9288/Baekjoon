#include <stdio.h>
#include <stdlib.h>
int n;
int visited[26][26] = { 0, };
int map[26][26] = { 0, };
int xx[4] = { 0,1,0,-1 }, yy[4] = { 1,0,-1,0 };
int c = 0;
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
void DFS(int x, int y, int cnt) {
    c++;
    visited[x][y] = 1;
    map[x][y] = cnt;
    for (int i = 0; i < 4; i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
        if (!visited[nx][ny] && map[nx][ny]) DFS(nx, ny, cnt);
    }
}
int main() {

    int cnt = 2;
    int res[10001] = { 0, };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                DFS(i, j, cnt);
                res[cnt - 2] = c;
                cnt++;
                c = 0;
            }
        }
    }
    qsort(res, cnt - 2, sizeof(int), cmp);
    printf("%d\n", cnt - 2);
    for (int i = 0; i < cnt - 2; i++)printf("%d\n", res[i]);
    return 0;
}