#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int main() {
    int n;
    int min = 2e9 + 1;
    int a[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    int s = 0, e = n - 1;
    int x, y;
    while (s < e) {
        int now = a[s] + a[e];
        if (abs(now) < min) {
            min = abs(now);
            x = s;
            y = e;
        }
        if (now > 0) e--;
        else s++;
    }
    printf("%d %d", a[x], a[y]);
    return 0;
}