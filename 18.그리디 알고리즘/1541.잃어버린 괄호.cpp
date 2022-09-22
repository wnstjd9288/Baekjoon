#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char s[51];
    int res = 0;
    int m = 0;
    scanf("%s", s);
    int n = 0;
    for (int i = 0; i < strlen(s); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            n *= 10;
            n += s[i] - 48;
        }
        else {
            if (m) res -= n;
            else res += n;
            n = 0;
            if (s[i] == '-') m = 1;
        }
        if (i == strlen(s) - 1) {
            if (m) res -= n;
            else res += n;
        }
    }
    printf("%d", res);
    return 0;
}