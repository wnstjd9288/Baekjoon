#include <stdio.h>
#include <stdlib.h>

int map[32][40001] = { 0, };
int main() {
    int n, a;

    scanf("%d", &n);
    scanf("%d", &a);

    map[0][a] = 1;
    int sum = a;

    for (int i = 1; i < n; i++) {
        scanf("%d", &a);
        map[i][a] = 1;
        for (int j = 1; j <= sum; j++) {
            if (map[i - 1][j] == 1) {
                map[i][j] = map[i][abs(j - a)] = map[i][j + a] = 1;
            }
        }
        sum += a;
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        if (map[n - 1][a]) printf("Y ");
        else printf("N ");
    }
    return 0;
}