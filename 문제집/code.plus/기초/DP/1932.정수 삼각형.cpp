#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {

    int n;
    int m;
    int map[500][500];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    m = map[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) map[i][j] += map[i - 1][j];
            else if (j == i) map[i][j] += map[i - 1][j - 1];
            else map[i][j] += max(map[i - 1][j - 1], map[i - 1][j]);
            if (m < map[i][j])m = map[i][j];
        }
    }
    printf("%d", m);
    return 0;
}