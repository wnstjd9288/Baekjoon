#include <stdio.h>
#include <stdlib.h>

typedef struct Cod {
    int x;
    int y;
}Cod;

int min(int a, int b) {
    return a < b ? a : b;
}

int n, m;
int map[301][301];

void turn(int index) {
    Cod start = { index,index };
    Cod end = { n - index + 1,m - index + 1 };

    int temp = map[start.x][start.y];
    for (int i = start.y; i < end.y; i++) {
        map[start.x][i] = map[start.x][i + 1];
    }
    for (int i = start.x; i < end.x; i++) {
        map[i][end.y] = map[i + 1][end.y];
    }
    for (int i = end.y; i > start.y; i--) {
        map[end.x][i] = map[end.x][i - 1];
    }
    for (int i = end.x; i > start.x + 1; i--) {
        map[i][start.y] = map[i - 1][start.y];
    }
    map[start.x + 1][start.y] = temp;
}

int main() {
    int r;
    long long k;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < min(n, m) / 2; i++) {
        k = (n - i * 2) * (m - i * 2) - (n - (i + 1) * 2) * (m - (i + 1) * 2);
        for (int j = 0; j < r % k; j++) turn(i + 1);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", map[i][j]);
        }puts("");
    }
    return 0;
}