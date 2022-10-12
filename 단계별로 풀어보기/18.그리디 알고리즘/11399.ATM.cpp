#include <stdio.h>
#include <stdlib.h>

int f(const void* a, const void* b) {
    return *(int*)a - *(int*)b;

}

int main() {

    int n;
    int t[1001];
    int sum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    qsort(t, n, sizeof(int), f);
    sum = t[0];
    for (int i = 1; i < n; i++) { t[i] += t[i - 1]; sum += t[i]; }
    printf("%d", sum);
    return 0;
}