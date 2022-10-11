#include <stdio.h>
#include <stdlib.h>

int wheel[1002][8];
void roll(int dir, int n, int prev) {

    if (wheel[n][2] + wheel[n + 1][6] == 1 && prev != n + 1) roll(dir * -1, n + 1, n);
    if (wheel[n][6] + wheel[n - 1][2] == 1 && prev != n - 1) roll(dir * -1, n - 1, n);
    if (dir == 1) {
        int temp = wheel[n][7];
        for (int i = 6; i >= 0; i--) wheel[n][i + 1] = wheel[n][i];
        wheel[n][0] = temp;
    }
    else {
        int temp = wheel[n][0];
        for (int i = 1; i < 8; i++) {
            wheel[n][i - 1] = wheel[n][i];
        }
        wheel[n][7] = temp;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j < 8; j++) wheel[i][j] = -1;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 8; j++) scanf("%1d", &wheel[i][j]);

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int n, dir;
        scanf("%d %d", &n, &dir);
        roll(dir, n, -1);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += wheel[i][0];
    printf("%d", sum);
    return 0;
}