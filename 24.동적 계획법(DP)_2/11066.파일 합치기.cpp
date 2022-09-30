#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++) {
        int n;
        int file;
        int sum[501] = { 0, };
        int dp[501][501] = { 0, };
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &file);
            sum[i] = sum[i - 1] + file;
        }
        for (int k = 1; k < n; k++) {
            int i = 1;
            int j = k + 1;
            for (int p = 0; p < n - k; p++) {
                dp[i][j] = 1e9;
                for (int q = 0; q < j - i; q++) {
                    dp[i][j] = min(dp[i][j], dp[i][i + q] + dp[i + q + 1][j] + sum[j] - sum[i - 1]);
                }
                i++;
                j++;
            }
        }
        printf("%d\n", dp[1][n]);
    }

    return 0;
}