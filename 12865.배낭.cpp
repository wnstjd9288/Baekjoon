#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int map[101][100001] = { 0, };
int main() {

    int n, k;
    int w[101], v[101];
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (w[i] <= j) {
                map[i][j] = max(map[i - 1][j], v[i] + map[i - 1][j - w[i]]);

            }
            else map[i][j] = map[i - 1][j];
        }
    }
    printf("%d", map[n][k]);
    return 0;
}