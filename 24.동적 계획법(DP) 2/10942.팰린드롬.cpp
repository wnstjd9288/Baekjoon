#include <stdio.h>
#include <stdlib.h>
int n,m;
int pel[2001] = { 0, };
int map[2001][2001] = { 0, };

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pel[i]);
        map[i][i] = 1;
    }
    for (int i = n; i > 0; i--) {
        for (int j = i; j <= n; j++) {
            if (pel[i] == pel[j]) {
                if (j - i <= 1) {
                    map[i][j] = 1;
                }
                else {
                    if (map[i + 1][i + 1] == 1 && map[i + 1][j - 1] == 1) {
                        map[i][j] = 1;
                    }
                }
            }
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", map[a][b]);
    }
    return 0;
}