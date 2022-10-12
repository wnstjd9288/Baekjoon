#include <stdio.h>
#include <stdlib.h>
long long sum[1000001] = { 0, };

int main() {

    int n, m, a;
    long long cnt[10001] = { 0, };
    long long res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        sum[i] = (sum[i - 1] + a) % m;
        cnt[sum[i]]++;
    }
    res = cnt[0];
    for (int i = 0; i < m; i++) {
        res += cnt[i] * (cnt[i] - 1) / 2;
    }
    printf("%lld", res);
    return 0;
}