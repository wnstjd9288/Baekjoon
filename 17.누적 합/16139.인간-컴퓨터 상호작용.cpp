#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnt[200001][27] = { 0, };

int main() {

    int len, n;
    char s[200001];
    scanf("%s", s);
    len = strlen(s);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 27; j++) {
            if (s[i] - 97 == j) cnt[i + 1][j] = cnt[i][j] + 1;
            else cnt[i + 1][j] = cnt[i][j];
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char c;
        int x, y;
        scanf("%*c %c %d %d", &c, &x, &y);
        printf("%d\n", cnt[y + 1][c - 97] - cnt[x][c - 97]);
    }

    return 0;
}