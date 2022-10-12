#include <stdio.h>
#include <stdlib.h>

int a, b, c;

long long int mul(long long int y) {

    if (y == 1) {
        return a % c;
    }

    long long int k = mul(y / 2);

    if (y % 2 == 0) {
        return k * k % c;
    }
    else return k * k % c * a % c;


}

int main() {
    scanf("%d %d %d", &a, &b, &c);
    printf("%lld", mul(b));
    return 0;
}