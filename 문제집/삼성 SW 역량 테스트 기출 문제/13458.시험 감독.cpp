#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[1000001];
int main() {
    int n;
    int b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &b, &c);
    long long sum = n;
    for (int i = 0; i < n; i++) {
        arr[i] -= b;
        if (arr[i] > 0) {
            sum += (arr[i] / c) + 1;
            if (arr[i] % c == 0) sum--;
        }
    }
    printf("%lld", sum);
    return 0;
}