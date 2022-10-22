#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
}Cod;

int min(int a, int b) {
    return a < b ? a : b;
}

char map[21][21];
int n, m;
int visited[21][21];
int dist[11][11];
int check[11] = { 0, };
int dt_cnt = 0;
int ans = 2e9;
Cod dt_list[11];
Cod que[10000001];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };

void Find_ans(int lev,int now,int sum) {
    if (lev == dt_cnt) {
        ans = min(ans, sum);
        return;
    }
    for (int i = 0; i < dt_cnt; i++) {
        if (now == i+1) continue;
        if (check[i]) continue;
        check[i] = 1;
        Find_ans(lev + 1, i + 1, sum + dist[now][i]);
        check[i] = 0;
    }

}

void BFS(Cod start,int num) {
    int h = -1, t = -1;
    que[++t] = start;
    visited[start.x][start.y] = 1;
    while (h != t) {
        Cod now = que[++h];
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
            if (map[next.x][next.y] == 'x') continue;
            if (visited[next.x][next.y]) continue;
            if (map[next.x][next.y] == '*') {
                for (int i = 0; i < dt_cnt; i++) {
                    if (next.x == dt_list[i].x && next.y == dt_list[i].y) {
                        dist[num][i] = visited[now.x][now.y];
                        break;
                    }
                }
            }
            visited[next.x][next.y] = visited[now.x][now.y] + 1;
            que[++t] = next;
        }
    }
}
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
}
int main() {

    while (1) {
        Cod start;
        bool flag = true;
        ans = 2e9;
        dt_cnt = 0;
        scanf("%d %d", &m, &n);
        if (!n && !m) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", map[i]);
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'o') start = { i,j };
                if (map[i][j] == '*') dt_list[dt_cnt++] = { i,j };
            }
        }

        for (int i = 0; i <= dt_cnt; i++)
            for (int j = 0; j < dt_cnt; j++) dist[i][j] = 0;
        init();
        BFS(start, 0);
        for (int i = 0; i < dt_cnt; i++) {
            if (!dist[0][i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < dt_cnt; i++) {
                init();
                BFS(dt_list[i], i + 1);
            }
            for (int i = 0; i < dt_cnt; i++) {
                check[i] = 1;
                Find_ans(1, i + 1, dist[0][i]);
                check[i] = 0;
            }
            printf("%d\n", ans);
        }
        else printf("-1\n");
    }
    return 0;
}