#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int dice[4][3] = { 0, };
    int map[21][21];
    int n, m, x, y, k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < k; i++) {
        int roll;
        int temp;
        scanf("%d", &roll);
        switch (roll) {
        case 1:
            if (y + 1 >= m) continue;
            y++;
            temp = dice[1][1];
            dice[1][1] = dice[1][0];
            dice[1][0] = dice[3][1];
            dice[3][1] = dice[1][2];
            dice[1][2] = temp;
            break;
        case 2:
            if (y - 1 < 0) continue;
            y--;
            temp = dice[1][1];
            dice[1][1] = dice[1][2];
            dice[1][2] = dice[3][1];
            dice[3][1] = dice[1][0];
            dice[1][0] = temp;
            break;
        case 4:
            if (x + 1 >= n) continue;
            x++;
            temp = dice[1][1];
            dice[1][1] = dice[2][1];
            dice[2][1] = dice[3][1];
            dice[3][1] = dice[0][1];
            dice[0][1] = temp;
            break;
        case 3:
            if (x - 1 < 0) continue;
            x--;
            temp = dice[1][1];
            dice[1][1] = dice[0][1];
            dice[0][1] = dice[3][1];
            dice[3][1] = dice[2][1];
            dice[2][1] = temp;
            break;
        }
        if (map[x][y]) {
            dice[3][1] = map[x][y];
            map[x][y] = 0;
        }
        else map[x][y] = dice[3][1];
        printf("%d\n", dice[1][1]);
    }
    return 0;
}