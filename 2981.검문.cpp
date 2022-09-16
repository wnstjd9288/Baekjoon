#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {

    int n,x;
    int m[101] = { 0, };
    int list[100001] = { 0, };
    int result[100001] = { 0, };
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    qsort(m, n, sizeof(int), compare);
    x = m[1] - m[0];
    int sq = sqrt(x);
    for (int i = 2; i <= sq; i++) {
        if (x % i == 0) {
            list[cnt++] = i;
            if (x / i != i) list[cnt++] = x / i;
        }
    }
    qsort(list, cnt, sizeof(int), compare);
    list[cnt++] = x;
    for (int i = 0; i < cnt; i++) {
        int key = m[0] % list[i];
        int j;
        for (j = 1; j < n; j++) {
            if (m[j] % list[i] != key) {
                break;
            }
        }
        if (j == n) printf("%d ", list[i]);
    }
    return 0;
}