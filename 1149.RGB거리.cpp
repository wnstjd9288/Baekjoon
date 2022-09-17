#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n;
    int map[1001][3] = { 0, };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int min = 99999999;
            for (int k = 0; k < 3; k++) {
                if (k == j)continue;
                if (min > map[i][j] + map[i - 1][k])min = map[i][j] + map[i - 1][k];
            }
            map[i][j] = min;
        }
    }
    int min = 9999999;
    for (int i = 0; i < 3; i++) {
        if (min > map[n - 1][i])min = map[n - 1][i];
    }
    printf("%d", min);

    return 0;
}