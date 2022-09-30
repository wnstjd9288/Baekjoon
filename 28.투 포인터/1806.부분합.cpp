#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int a[100001];
long long sum[100001] = { 0, };
int main() {
    int n, x;
    long long min = 2e9 + 1;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    int s = 0, e = 1;
    while (1) {
        if (s == n && e == n) break;
        long long now = sum[e] - sum[s];
        if (now >= x) {
            if (e - s < min) min = e - s;
        }
        if (now > x) {
            s++;
        }
        else {
            if (e + 1 <= n) e++;
            else s++;
        }
    }
    if (min == 2e9 + 1) printf("0");
    else printf("%lld", min);
    return 0;
}