#include <stdio.h>
#include <stdlib.h>
int map[128][128];
int p_b = 0;
int p_w = 0;
void paper(int lev, int x1, int y1, int x2, int y2) {
    if (lev == 1) {
        if (map[x1][y1]) p_b++;
        else p_w++;
        return;
    }
    int cnt = 0;
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            cnt += map[i][j];
        }
    }
    if (cnt == lev * lev) {
        p_b++;
        return;
    }
    else if (cnt == 0) {
        p_w++;
        return;
    }
    else {
        paper(lev / 2, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
        paper(lev / 2, (x1 + x2) / 2, y1, x2, (y1 + y2) / 2);
        paper(lev / 2, x1, (y1 + y2) / 2, (x1 + x2) / 2, y2);
        paper(lev / 2, (x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
    }
}

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);
    paper(n, 0, 0, n, n);
    printf("%d\n%d", p_w, p_b);
    return 0;
}