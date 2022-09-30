#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int main() {
    int n, x;
    int cnt = 0;
    int a[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    qsort(a, n, sizeof(int), cmp);
    int s=0, e=n-1;
    while (s < e) {
        int now = a[s] + a[e];
        if (now > x) e--;
        else s++;
        if (now == x)cnt++;
    }
    printf("%d", cnt);
    return 0;
}