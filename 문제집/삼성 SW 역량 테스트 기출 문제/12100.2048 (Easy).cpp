#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct grid {
    int map[21][21] = { 0, };
    int cnt;
}Map;

int n;
Map que[100001];
int xx[4] = { -1,1,0,0 }, yy[4] = { 0,0,-1,1 };
int max = -1;
void _2048(Map start) {
    int h = -1, t = -1;

    que[++t] = start;
    while (h != t) {
        Map now = que[++h];
        if (now.cnt == 5) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (now.map[i][j] > max)max = now.map[i][j];
                }
            }
            continue;
        }
        for (int k = 0; k < 4; k++) {
            Map next = now;
            Map check;
            next.cnt = now.cnt + 1;
            if (k % 2 == 1) {
                for (int i = n - 1; i >= 0; i--) {
                    for (int j = n - 1; j >= 0; j--) {
                        if (next.map[i][j]) {
                            int nowx = i, nowy = j;
                            while (1) {
                                int nextx = nowx + xx[k];
                                int nexty = nowy + yy[k];
                                if (nextx >= n || nexty >= n) break;
                                if (!next.map[nextx][nexty]) {
                                    next.map[nextx][nexty] = next.map[nowx][nowy];
                                    next.map[nowx][nowy] = 0;
                                    check.map[nextx][nexty] = check.map[nowx][nowy];
                                    check.map[nowx][nowy] = 0;
                                }
                                else {
                                    if (next.map[nextx][nexty] == next.map[nowx][nowy]) {
                                        if (!check.map[nextx][nexty] && !check.map[nowx][nowy]) {
                                            next.map[nextx][nexty] += next.map[nowx][nowy];
                                            next.map[nowx][nowy] = 0;
                                            check.map[nextx][nexty] = 1;
                                            check.map[nowx][nowy] = 0;
                                        }
                                    }
                                    break;
                                }

                                nowx = nextx;
                                nowy = nexty;
                            }
                        }
                    }
                }
                bool flag = true;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (now.map[i][j] != next.map[i][j]) { flag = false; break; }
                    }
                    if (!flag) break;
                }
                if (!flag) {
                    que[++t] = next;
                }
            }
            else {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (next.map[i][j]) {
                            int nowx = i, nowy = j;
                            while (1) {
                                int nextx = nowx + xx[k];
                                int nexty = nowy + yy[k];
                                if (nextx < 0 || nexty < 0) break;
                                if (!next.map[nextx][nexty]) {
                                    next.map[nextx][nexty] = next.map[nowx][nowy];
                                    next.map[nowx][nowy] = 0;
                                    check.map[nextx][nexty] = check.map[nowx][nowy];
                                    check.map[nowx][nowy] = 0;
                                }
                                else{
                                    if (next.map[nextx][nexty] == next.map[nowx][nowy]) {
                                        if (!check.map[nextx][nexty] && !check.map[nowx][nowy]) {
                                            next.map[nextx][nexty] += next.map[nowx][nowy];
                                            next.map[nowx][nowy] = 0;
                                            check.map[nextx][nexty] = 1;
                                            check.map[nowx][nowy] = 0;
                                        }
                                    }
                                    break;
                                }
                                nowx = nextx;
                                nowy = nexty;
                            }
                        }
                    }
                }
                bool flag = true;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (now.map[i][j] != next.map[i][j]) { flag = false; break; }
                    }
                    if (!flag) break;
                }
                if (!flag) {
                    que[++t] = next;
                }
            }
        }
    }
}

int main() {
    Map map;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map.map[i][j]);
            if (map.map[i][j] > max)max = map.map[i][j];
        }
    }
    map.cnt = 0;
    _2048(map);
    printf("%d", max);
    return 0;
}