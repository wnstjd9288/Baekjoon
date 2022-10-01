#include <stdio.h>
#include <stdlib.h>

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long weight[101][101];
int history[101][101] = { 0, };
int cnt = 0;
int res[101];
void Floyd(int n) {
    for (int i = 1; i <= n; i++) weight[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (weight[i][j] > weight[i][k] + weight[k][j]) {
                    weight[i][j] = weight[i][k] + weight[k][j];
                    history[i][j] = k;
                }
            }
        }
    }
}
void Mk_res(int s, int e) {
    if (!history[s][e]) {
        res[cnt++] = e;
        return;
    }
    Mk_res(s, history[s][e]);
    Mk_res(history[s][e], e);
}
int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) weight[i][j] = 1e9;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        weight[u][v] = min(weight[u][v], w);
    }
    Floyd(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (weight[i][j] == 1e9)printf("0 ");
            else printf("%lld ", weight[i][j]);
        }puts("");
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (weight[i][j] == 1e9 || i == j) printf("0\n");
            else { 
                cnt = 0;
                Mk_res(i, j); 
                printf("%d %d ", cnt+1, i);
                for (int k = 0; k < cnt; k++) printf("%d ", res[k]);
                puts("");
            }
        }
    }
    return 0;
}