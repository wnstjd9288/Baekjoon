#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[51][16];
int exist[27] = { 0, };
int list[27] = { 0, };
int n, k, cnt = 0;
int max = -1;

void com(int index, int now, int cur) {
    if (now == k) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < strlen(str[i]); j++) {
                if (!(cur & (1 << (str[i][j] - 'a')))) break;
                if (j == strlen(str[i]) - 1) c++;
            }
        }
        if (max < c)max = c;
        return;
    }
    for (int i = index; i < cnt; i++) {
        if (!(cur & (1 << list[i]))) {
            com(i, now + 1, cur | (1 << list[i]));
        }
    }
}

int main() {

    int cur = 1;
    cur = cur | (1 << 2);
    cur = cur | (1 << 8);
    cur = cur | (1 << 13);
    cur = cur | (1 << 19);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        for (int j = 0; j < strlen(str[i]); j++) {
            exist[str[i][j] - 'a'] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (exist[i] && !(cur & (1 << i))) {
            list[cnt++] = i;
        }
    }
    k -= 5;
    if (k < 0) printf("0");
    else if (k >= cnt) printf("%d", n);
    else {
        com(0, 0, cur);
        printf("%d", max);
    }
    return 0;
}