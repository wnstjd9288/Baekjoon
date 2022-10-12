#include <stdio.h>
#include <stdlib.h>

long long int a = 1, b = 1;
long long int mod = 1000000007;
long long int mul(long long int y) {
    if (y == 1) {
        return b % mod;
    }
    long long int k = mul(y / 2) % mod;
    if (y % 2 == 0) {
        return k * k % mod;
    }
    else return k * k % mod * b % mod;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = k + 1; i <= n; i++) a = a * i % mod;

    for (int i = 1; i <= n - k; i++) b = b * i % mod;

    b = mul(mod - 2);

    printf("%lld", a * b % mod);
    return 0;
}
