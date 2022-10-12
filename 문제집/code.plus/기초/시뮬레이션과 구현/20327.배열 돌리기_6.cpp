#include <stdio.h>
#include <stdlib.h>

typedef struct Cod {
    int x;
    int y;
}Cod;

int map[130][130] = { 0, };
int N, n, r, l;

void turn(int k, int lev, Cod start, Cod end) {

    Cod mid = { (start.x + end.x) / 2,(start.y + end.y) / 2 };
    if (lev == l) {
        int temp[130][130];
        if (k == 1 || k == 5) {
            for (int i = start.x; i < end.x; i++) {
                for (int j = start.y; j < end.y; j++) {
                    temp[i][j] = map[end.x + start.x - i - 1][j];
                }
            }
        }
        if (k == 2 || k == 6) {
            for (int i = start.x; i < end.x; i++) {
                for (int j = start.y; j < end.y; j++) {
                    temp[i][j] = map[i][end.y + start.y - j - 1];
                }
            }
        }
        if (k == 3 || k == 8) {
            for (int i = 0; i < end.x - start.x; i++) {
                for (int j = 0; j < end.y - start.y; j++) {
                    temp[start.x + i][start.y + j] = map[end.x - 1 - j][start.y + i];
                }
            }
        }
        if (k == 4 || k == 7) {
            for (int i = 0; i < end.x - start.x; i++) {
                for (int j = 0; j < end.y - start.y; j++) {
                    temp[start.x + i][start.y + j] = map[start.x + j][end.y - 1 - i];
                }
            }
        }
        for (int i = start.x; i < end.x; i++) {
            for (int j = start.y; j < end.y; j++) {
                map[i][j] = temp[i][j];
            }
        }
        return;
    }
    turn(k, lev - 1, start, mid);
    turn(k, lev - 1, { start.x,mid.y }, { mid.x,end.y });
    turn(k, lev - 1, { mid.x,start.y }, { end.x,mid.y });
    turn(k, lev - 1, mid, end);

}

int main() {

    scanf("%d %d", &N, &r);
    n = 1;
    for (int i = 0; i < N; i++) n *= 2;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        int k;
        scanf("%d %d", &k, &l);
        if (k <= 4 && l == 0) continue;
        int temp[130][130];
        Cod start = { 0,0 }, end = { n,n };
        switch (k)
        {
        case 5:
            for (int i = start.x; i < end.x; i++) {
                for (int j = start.y; j < end.y; j++) {
                    temp[i][j] = map[end.x + start.x - i - 1][j];
                }
            }
            break;
        case 6:
            for (int i = start.x; i < end.x; i++) {
                for (int j = start.y; j < end.y; j++) {
                    temp[i][j] = map[i][end.y + start.y - j - 1];
                }
            }
            break;
        case 7:
            for (int i = 0; i < end.x - start.x; i++) {
                for (int j = 0; j < end.y - start.y; j++) {
                    temp[start.x + i][start.y + j] = map[end.x - 1 - j][start.y + i];
                }
            }
            break;
        case 8:
            for (int i = 0; i < end.x - start.x; i++) {
                for (int j = 0; j < end.y - start.y; j++) {
                    temp[start.x + i][start.y + j] = map[start.x + j][end.y - 1 - i];
                }
            }
            break;
        }
        if (5 <= k) {
            for (int i = start.x; i < end.x; i++) {
                for (int j = start.y; j < end.y; j++) {
                    map[i][j] = temp[i][j];
                }
            }
        }
        turn(k, N, { 0,0 }, { n,n });
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", map[i][j]);
        }puts("");
    }
    return 0;
}