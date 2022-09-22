#include <stdio.h>
#include <stdlib.h>
int map[64][64];
char s[100001];
int c = 0;
void quad(int lev, int x1, int y1, int x2, int y2) {
    int cnt = 0;
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            cnt += map[i][j];
        }
    }
    if (cnt == 0) {
        s[c++] = '0';
        return;
    }
    else if (cnt == lev * lev) {
        s[c++] = '1';
        return;
    }
    else {
        if (lev == 2) {
            s[c++] = '(';
            for (int i = x1; i < x2; i++) {
                for (int j = y1; j < y2; j++) {
                    s[c++] = map[i][j] + 48;
                }
            }
            s[c++] = ')';
            return;
        }
        s[c++] = '(';
        quad(lev / 2, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
        quad(lev / 2, x1, (y1 + y2) / 2, (x1 + x2) / 2, y2);
        quad(lev / 2, (x1 + x2) / 2, y1, x2, (y1 + y2) / 2);
        quad(lev / 2, (x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
        s[c++] = ')';
    }
}
int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    quad(n, 0, 0, n, n);
    printf("%s", s);
    return 0;
}