#include <stdio.h>
#include <stdlib.h>

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long weight[401][401];
void Floyd(int n) {
    for (int i = 1; i <= n; i++) weight[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (weight[i][j] > weight[i][k] + weight[k][j]) {
                    weight[i][j] = weight[i][k] + weight[k][j];
                }
            }
        }
    }
}
int main() {
    int n, m;
    int ans = 1e9;
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
        for (int j = i+1; j <= n; j++) {
            if (weight[i][j] != 1e9 && weight[j][i] != 1e9) {
                ans = min(ans, weight[i][j] + weight[j][i]);
            }
        }
    }
    if (ans == 1e9) printf("-1");
    else printf("%d", ans);
    return 0;
}