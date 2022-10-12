#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long v[100000];
long long w[100001];
long long min[100001] = { 0, };
int main() {

    int n;
    long long res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld", &v[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
        min[i] = w[i];
        if (i) {
            if (min[i - 1] < w[i]) min[i] = min[i - 1];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        res += min[i] * v[i];
    }
    printf("%lld", res);
    return 0;
}