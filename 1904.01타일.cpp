#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void f(int n) {
    long long a = 1, b = 1, c;
    for (int i = 1; i < n; i++) {
        c = (a + b) % 15746;
        a = b;
        b = c;
    }
    printf("%lld", b);
}

int main() {
    int n;
    scanf("%d", &n);
    f(n);
    return 0;
}