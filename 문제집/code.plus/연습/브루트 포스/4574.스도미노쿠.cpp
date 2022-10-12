#include <stdio.h>
#include <stdlib.h>

int map[10][10] = { 0, };
int domino[10][10] = { 0, };
bool fin = false;
bool checkCol(int c,int num) {
    for (int i = 0; i < 9; i++)
        if (map[i][c] == num) return false;
    return true;
}

bool checkRow(int r,int num) {
    for (int i = 0; i < 9; i++)
        if (map[r][i] == num) return false;
    return true;
}

bool checkBox(int r,int c,int num) {
    int x = r / 3 * 3;
    int y = c / 3 * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (map[x + i][y + j] == num) return false;
    return true;
}

bool check(int r, int c, int num) {
    return checkBox(r, c, num) && checkCol(c, num) && checkRow(r, num);
}

void sudominoku(int index) {
    if (fin) return;
    if (index >= 81) {
        fin = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d", map[i][j]);
            }puts("");
        }
        return;
    }
    int x = index / 9;
    int y = index % 9;
    if (map[x][y]) sudominoku(index + 1);
    else {
        for (int i = 1; i <= 8; i++) {
            for (int j = i + 1; j <= 9; j++) {
                if (!domino[i][j]) {
                    domino[i][j] = domino[j][i] = 1;
                    if (y + 1 < 9 && !map[x][y + 1]) {
                        if (check(x, y, i) && check(x, y + 1, j)) {
                            map[x][y] = i;
                            map[x][y + 1] = j;
                            sudominoku(index + 1);
                            map[x][y] = map[x][y + 1] = 0;
                        }
                        if (check(x, y, j) && check(x, y + 1, i)) {
                            map[x][y] = j;
                            map[x][y + 1] = i;
                            sudominoku(index + 1);
                            map[x][y] = map[x][y + 1] = 0;
                        }
                    }
                    if (x + 1 < 9 && !map[x + 1][y]) {
                        if (check(x, y, i) && check(x + 1, y, j)) {
                            map[x][y] = i;
                            map[x + 1][y] = j;
                            sudominoku(index + 1);
                            map[x][y] = map[x + 1][y] = 0;
                        }
                        if (check(x, y, j) && check(x + 1, y, i)) {
                            map[x][y] = j;
                            map[x + 1][y] = i;
                            sudominoku(index + 1);
                            map[x][y] = map[x + 1][y] = 0;
                        }
                    }
                    domino[i][j] = domino[j][i] = 0;
                }
            }
        }
    }
}

void init() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            map[i][j] = domino[i + 1][j + 1] = 0;
    fin = false;
}

int main() {

    for (int test = 1;; test++) {
        int n;
        scanf("%d", &n);
        if (n == 0)break;
        init();
        for (int i = 0; i < n; i++) {
            int a1, a2;
            char b1, c1, b2, c2;
            scanf("%d %c%c %d %c%c", &a1, &b1, &c1, &a2, &b2, &c2);
            map[b1 - 65][c1 - 49] = a1;
            map[b2 - 65][c2 - 49] = a2;
            domino[a1][a2] = domino[a2][a1] = 1;
        }
        for (int i = 0; i < 9; i++) {
            char a, b;
            scanf("%*c%c%c", &a, &b);
            map[a - 65][b - 49] = i + 1;
        }
        printf("Puzzle %d\n", test);
        sudominoku(0);
    }
    return 0;
}