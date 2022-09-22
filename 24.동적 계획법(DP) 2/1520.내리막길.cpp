#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int X;
    int Y;
}cod;

int n, m;
int map[601][601] = { 0, };
int dp[601][601] = { 0, };
cod xy[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int max(int a, int b) {
    return a > b ? a : b;
}

int DFS(cod now) {

    if (now.X == n && now.Y == m) { return 1; }
    if (dp[now.X][now.Y] != -1) return dp[now.X][now.Y];

    dp[now.X][now.Y] = 0;
    for (int i = 0; i < 4; i++) {
        cod next = now;
        next.X += xy[i].X;
        next.Y += xy[i].Y;
        if (next.X > n || next.X <= 0 || next.Y > m || next.Y <= 0) continue;
        if (map[now.X][now.Y] > map[next.X][next.Y]) {
            dp[now.X][now.Y] += DFS(next);
        }
    }
    return dp[now.X][now.Y];
}

int main() {

    cod start = { 1,1 };
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
    printf("%d",DFS(start));
    return 0;
}