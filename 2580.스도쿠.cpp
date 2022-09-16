#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int map[9][9];
int check[9][9][9];
int cnt = 0;
void sudoku(int lev) {
    if (lev == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", map[i][j]);
            }
            puts("");
        }
        exit(0);
    }
    int x = lev / 9;
    int y = lev % 9;
    if (map[x][y]) sudoku(lev + 1);
    else {
        for (int i = 0; i < 9; i++) {
            if (!check[x][y][i]) map[x][y] = i + 1;
            else continue;
            bool is_right = true;
            for (int j = 0; j < 9; j++) {
                if (j != x && map[x][y] == map[j][y]) is_right = false;
                if (j != y && map[x][y] == map[x][j]) is_right = false;
            }
            int center_x = 0;
            int center_y = 0;
            for (int j = 1; j <= 7; j += 3) {
                for (int k = 1; k <= 7; k += 3) {
                    if (abs(j - x) <= 1 && abs(k - y) <= 1) {
                        center_x = j;
                        center_y = k;
                    }
                }
            }
            for (int j = center_x - 1; j <= center_x + 1; j++) {
                for (int k = center_y - 1; k <= center_y + 1; k++) {
                    if (j == x && k == y) continue;
                    if (map[x][y] == map[j][k]) is_right = false;
                }
            }
            if (is_right) sudoku(lev + 1);
            map[x][y] = 0;
        }
    }
}

int main() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!map[i][j]) {
                int center_x = 0;
                int center_y = 0;
                for (int k = 0; k < 9; k++) {
                    if (map[i][k]) check[i][j][map[i][k] - 1] = 1;
                    if (map[k][j]) check[i][j][map[k][j] - 1] = 1;
                }
                for (int x = 1; x <= 7; x += 3) {
                    for (int y = 1; y <= 7; y += 3) {
                        if (abs(x - i) <= 1 && abs(y - j) <= 1) {
                            center_x = x;
                            center_y = y;
                        }
                    }
                }
                for (int x = center_x - 1; x <= center_x + 1; x++) {
                    for (int y = center_y - 1; y <= center_y + 1; y++) {
                        if (map[x][y]) check[i][j][map[x][y] - 1] = 1;
                    }
                }
            }
        }
    }
    sudoku(0);
    return 0;
}