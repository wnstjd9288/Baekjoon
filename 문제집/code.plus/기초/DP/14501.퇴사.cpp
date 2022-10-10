#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {

    int n;
    int DP[101] = { 0, };
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int t, p;
        scanf("%d %d", &t, &p);
        DP[i] = max(DP[i - 1], DP[i]);
        DP[i + t] = max(DP[i + t], DP[i] + p);
    }
    printf("%d", max(DP[n + 1], DP[n]));
    return 0;
}