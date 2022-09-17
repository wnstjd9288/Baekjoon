#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int stair[101][10];
    scanf("%d", &n);
    stair[1][0] = 0;
    for (int i = 1; i <= 9; i++) stair[1][i] = 1;

    for (int i = 2; i < n + 1; i++) {
        stair[i][0] = stair[i - 1][1] % 1000000000;
        for (int j = 1; j <= 8; j++) {
            stair[i][j] = (stair[i - 1][j - 1] + stair[i - 1][j + 1]) % 1000000000;
        }
        stair[i][9] = stair[i - 1][8] % 1000000000;
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = (sum + stair[n][i]) % 1000000000;
    }
    printf("%d\n", sum);
    return 0;
}