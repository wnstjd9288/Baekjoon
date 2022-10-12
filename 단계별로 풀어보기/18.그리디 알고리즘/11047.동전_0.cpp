#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, k;
    int coinlist[11] = { 0, };
    int cnt = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &coinlist[i]);
    for (int i = n - 1; i >= 0; i--) {
        cnt += k / coinlist[i];
        k %= coinlist[i];
    }
    printf("%d", cnt);
    return 0;
}