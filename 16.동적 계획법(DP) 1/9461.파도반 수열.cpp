#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    long long s[10001];
    s[0] = 1;
    s[1] = 1;
    s[2] = 1;
    s[3] = 2;
    s[4] = 2;
    for (int i = 5; i <= 100; i++) {
        s[i] = s[i - 1] + s[i - 5];
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        printf("%lld\n", s[a - 1]);
    }
    return 0;
}