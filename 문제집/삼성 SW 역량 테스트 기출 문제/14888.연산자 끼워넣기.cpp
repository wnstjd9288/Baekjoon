#include <stdio.h>
#include <stdlib.h>

int arr[101];
int max = -2e9;
int min = 2e9;
void cal(int plus, int minus, int mul, int div, int cnt, int sum) {
    if (plus + minus + mul + div == 0) {
        if (sum > max) max = sum;
        if (sum < min) min = sum;
    }
    if (plus) {
        cal(plus - 1, minus, mul, div, cnt + 1, sum + arr[cnt]);
    }
    if (minus) {
        cal(plus, minus - 1, mul, div, cnt + 1, sum - arr[cnt]);
    }
    if (mul) {
        cal(plus, minus, mul - 1, div, cnt + 1, sum * arr[cnt]);
    }
    if (div) {
        cal(plus, minus, mul, div - 1, cnt + 1, sum / arr[cnt]);
    }

}

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    cal(a, b, c, d, 1, arr[0]);
    printf("%d\n%d", max, min);
    return 0;
}