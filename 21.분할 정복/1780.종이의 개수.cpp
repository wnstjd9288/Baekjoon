#include <stdio.h>
#include <stdlib.h>
int map[2200][2200];
int res[3] = { 0, };

void paper(int lev, int x1, int y1, int x2, int y2) {

    if (lev == 1) {
        if (map[x1][y1] < 0) res[0]++;
        else if (map[x1][y1] == 0) res[1]++;
        else res[2]++;
        return;
    }
    int cnt = 0;
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            cnt += map[i][j];
        }
    }
    if (cnt == lev * lev * -10) {
        res[0]++;
        return;
    }
    else if (cnt == 0) {
        res[1]++;
        return;
    }
    else if (cnt == lev * lev) {
        res[2]++;
        return;
    }
    else {
        paper(lev / 3, x1, y1, (x1 * 2 + x2) / 3, (y1 * 2 + y2) / 3);
        paper(lev / 3, (x1 * 2 + x2) / 3, y1, (x1 + x2 * 2) / 3, (y1 * 2 + y2) / 3);
        paper(lev / 3, (x1 + x2 * 2) / 3, y1, x2, (y1 * 2 + y2) / 3);

        paper(lev / 3, x1, (y1 * 2 + y2) / 3, (x1 * 2 + x2) / 3, (y1 + y2 * 2) / 3);
        paper(lev / 3, (x1 * 2 + x2) / 3, (y1 * 2 + y2) / 3, (x1 + x2 * 2) / 3, (y1 + y2 * 2) / 3);
        paper(lev / 3, (x1 + x2 * 2) / 3, (y1 * 2 + y2) / 3, x2, (y1 + y2 * 2) / 3);

        paper(lev / 3, x1, (y1 + y2 * 2) / 3, (x1 * 2 + x2) / 3, y2);
        paper(lev / 3, (x1 * 2 + x2) / 3, (y1 + y2 * 2) / 3, (x1 + x2 * 2) / 3, y2);
        paper(lev / 3, (x1 + x2 * 2) / 3, (y1 + y2 * 2) / 3, x2, y2);
    }

}

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == -1) map[i][j] *= 10;
        }
    }
    paper(n, 0, 0, n, n);
    for (int i = 0; i < 3; i++) printf("%d\n", res[i]);
    return 0;
}