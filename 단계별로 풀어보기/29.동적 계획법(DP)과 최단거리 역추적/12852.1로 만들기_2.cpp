#include <stdio.h>
#include <stdlib.h>
int min(int a, int b) {
    if (a > b) return b;
    else return a;
}
int dp[1000001] = { 0, };
int history[1000001] = { 0, };
int main() {

    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        history[i] = i - 1;
        if (i % 3 == 0) {
            if (dp[i] > dp[i / 3] + 1) {
                dp[i] = dp[i / 3] + 1;
                history[i] = i / 3;
            }
        }
        if (i % 2 == 0) {
            if (dp[i] > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                history[i] = i / 2;
            }
        }
    }
    printf("%d\n", dp[n]);
    for (int i = n; i != 0; i = history[i]) {
        printf("%d ", i);
    }
    return 0;
}