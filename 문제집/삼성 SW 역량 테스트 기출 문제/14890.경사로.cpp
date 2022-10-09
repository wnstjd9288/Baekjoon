#include <stdio.h>
#include <stdlib.h>

int n, l;
int map[101][101] = { 0, };

bool road(int k, bool ver) {

    int line[101] = { 0, };
    for (int i = 1; i <= n; i++) {
        if (ver) {
            if (map[k][i] != map[k][i - 1]) line[i] = 1;
            else line[i] = line[i - 1] + 1;
            if (map[k][i - 1] > map[k][i]) {
                if (map[k][i - 1] == map[k][i] + 1) line[i] -= l;
                else return false;
            }
        }
        else {
            if (map[i][k] != map[i - 1][k]) line[i] = 1;
            else line[i] = line[i - 1] + 1;
            if (map[i - 1][k] > map[i][k]) {
                if (map[i - 1][k] == map[i][k] + 1) line[i] -= l;
                else return false;
            }
        }
    }
    for (int i = n; i >= 2; i--) {
        if (ver) {
            if (map[k][i - 1] < map[k][i]) {
                if (map[k][i - 1] == map[k][i] - 1) line[i - 1] -= l;
                else return false;
            }
            if (map[k][i] == map[k][i - 1]) line[i - 1] = line[i];
        }
        else {
            if (map[i - 1][k] < map[i][k]) {
                if (map[i - 1][k] == map[i][k] - 1) line[i - 1] -= l;
                else return false;
            }
            if (map[i][k] == map[i - 1][k]) line[i - 1] = line[i];;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (line[i] < 0) return false;
    }
    return true;
}

int main() {

    int cnt = 0;
    scanf("%d %d", &n, &l);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if(road(i, true)) cnt++;
        if(road(i, false)) cnt++;
    }
    printf("%d", cnt);
    return 0;
}