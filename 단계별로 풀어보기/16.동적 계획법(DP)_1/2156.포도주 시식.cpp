#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
    int n;
    int stair[100001];
    int dp[100001];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &stair[i]);
    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = stair[i] + max(dp[i - 2], dp[i - 3] + stair[i - 1]);
        dp[i] = max(dp[i], dp[i - 1]);
    }
    printf("%d", dp[n]);
    return 0;
}