#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char list[11][9];
int sum[27] = { 0, };
int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", list[i]);
    }
    for (int i = 0; i < n; i++) {
        int cal = 1;
        for (int j = strlen(list[i]) - 1; j >= 0; j--) {
            sum[list[i][j] - 65] += cal;
            cal *= 10;
        }
    }
    qsort(sum, 26, sizeof(int), cmp);
    int res = 0;
    for (int i = 0; i < 9; i++) {
        res += sum[i] * (9 - i);
    }
    printf("%d", res);
    return 0;
}