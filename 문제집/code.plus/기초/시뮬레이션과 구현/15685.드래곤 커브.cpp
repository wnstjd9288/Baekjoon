#include <stdio.h>
#include <stdlib.h>

typedef struct Cod {
    int x;
    int y;
}Cod;

int cnt = 0;
Cod xy[4] = { {0,1},{-1,0},{0,-1},{1,0} };
Cod now = { 0,0 };
int arr[2000];
int map[101][101] = { 0, };
void dragon_curve(int d,int dir) {
    if (d == 0) {
        arr[++cnt] = dir;
        return;
    }
    dragon_curve(d - 1, dir);
    for (int i = cnt + 1; i <= cnt * 2; i++) {
        arr[i] = (arr[2 * cnt - i + 1] + 1) % 4;
    }
    cnt *= 2;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y, dir, gen;
        scanf("%d %d %d %d", &x, &y, &dir, &gen);
        cnt = 0;
        dragon_curve(gen, dir);
        map[y][x] = 1;
        for (int j = 1; j <= cnt; j++) {
            x += xy[arr[j]].y;
            y += xy[arr[j]].x;
            if (x > 100 || y > 100 | x < 0 || y < 0) continue;
            map[y][x] = 1;
        }
    }
    cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}