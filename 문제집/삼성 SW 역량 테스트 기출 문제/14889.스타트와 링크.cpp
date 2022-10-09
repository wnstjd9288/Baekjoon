#include <stdio.h>
#include <stdlib.h>
int n;
int map[21][21];
int min = 2e9;
bool team[21];
void match(int t, int start) {
    if (t > n / 2) return;
    if (t == n / 2) {
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (team[i] && team[j]) t1 += map[i][j];
                if (!team[i] && !team[j]) t2 += map[i][j];
            }
        }
        if (min > abs(t1 - t2)) min = abs(t1 - t2);
        return;
    }
    for (int i = start; i < n; i++) {
        team[i] = true;
        match(t + 1, i + 1);
        team[i] = false;
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    match(0,0);
    printf("%d", min);

    return 0;
}