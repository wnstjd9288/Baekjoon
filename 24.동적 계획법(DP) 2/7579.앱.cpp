#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int m;
    int c;
}App;
int max(int a, int b) {
    return a > b ? a : b;
}
int back[101][10001] = { 0, };
int main() {

    int n, m;
    int sum = 0;
    int res = 10000;
    App app[101];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &app[i].m);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &app[i].c);
        sum += app[i].c;
    }
    for (int i = 1; i <= n; i++) {
        back[i][app[i].c] = app[i].m;
        for (int j = 0; j <= sum; j++) {
            if (back[i - 1][j] != 0) {
                back[i][j + app[i].c] = max(back[i - 1][j + app[i].c], back[i - 1][j] + app[i].m); 
                back[i][j] = max(back[i][j], back[i - 1][j]);
            }
            if (i == n) {
                if (back[i][j] >= m) {
                    if (res > j)res = j;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}