#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int x;
    int y;
    int z;
}cod;

int n, m, k;
int h = -1, t = -1;
int visited[101][101][101] = { 0, };
int map[101][101][101] = { 0, };
cod que[1000001] = { 0, };
cod xyz[6] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
void BFS() {

    while (h != t) {
        cod now = que[++h];
        for (int i = 0; i < 6; i++) {
            cod next = now;
            next.x += xyz[i].x;
            next.y += xyz[i].y;
            next.z += xyz[i].z;
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n || next.z < 0 || next.z >= k) continue;
            if (map[next.x][next.y][next.z] == -1)continue;
            if (!visited[next.x][next.y][next.z] || visited[next.x][next.y][next.z] > visited[now.x][now.y][now.z] + 1) {
                visited[next.x][next.y][next.z] = visited[now.x][now.y][now.z] + 1;
                que[++t] = next;
            }
        }
    }

}

int main() {

    int max = -1;
    scanf("%d %d %d", &n, &m, &k);

    for (int l = 0; l < k; l++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j][l]);
                if (map[i][j][l] == 1) {
                    visited[i][j][l] = 1;
                    que[++t].x = i;
                    que[t].y = j;
                    que[t].z = l;
                }
            }
        }
    }
    BFS();
    for (int l = 0; l < k; l++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j][l] != -1 && visited[i][j][l] == 0) {
                    printf("-1");
                    exit(0);
                }
                if (visited[i][j][l] > max) max = visited[i][j][l];
            }
        }
    }
    printf("%d", max - 1);
    return 0;
}