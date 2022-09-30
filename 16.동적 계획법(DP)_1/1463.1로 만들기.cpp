#include <stdio.h>
#include <stdlib.h>
int min(int a, int b) {
    if (a > b) return b;
    else return a;
}
int dp[10000001];
int main() {

    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    printf("%d", dp[n]);
    return 0;
}