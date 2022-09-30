#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int A;
    int B;
}Matrix;

int min(int a, int b) {
    return a < b ? a : b;
}
int main() {

    int n;
    Matrix Mat[501];
    int dp[501][501] = { 0, };
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &Mat[i].A, &Mat[i].B);
    }
    for (int k = 1; k < n; k++) {
        int i = 1;
        int j = k + 1;
        for (int p = 0; p < n - k; p++) {
            dp[i][j] = 1e9;
            for (int q = 0; q < j - i; q++) {
                dp[i][j] = min(dp[i][j], dp[i][i + q] + dp[i + q + 1][j] + Mat[i].A * Mat[i + q].B * Mat[j].B);
            }
            i++;
            j++;
        }
    }
    printf("%d", dp[1][n]);
    return 0;
}