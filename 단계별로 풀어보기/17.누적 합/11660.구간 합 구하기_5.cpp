#include <stdio.h>
#include <stdlib.h>
long long sum[1025][1025] = { 0, };

int main() {

    int n, m;
    int a;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a);
            sum[i][j] = sum[i][j - 1] + a;
        }
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        long long ans = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = x1; j <= x2; j++) {
            ans += sum[j][y2] - sum[j][y1 - 1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}