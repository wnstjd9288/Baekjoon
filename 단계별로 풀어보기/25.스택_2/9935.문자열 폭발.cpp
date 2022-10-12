#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b) {
    return a > b ? a : b;
}
char s[1000001];
char stack[1000001];
int main() {

    int top = -1;
    char boom[37];
    scanf("%s", s);
    scanf("%s", boom);
    int slen = strlen(s);
    int blen = strlen(boom);

    for (int i = 0; i < slen; i++) {
        int cnt = 0;
        stack[++top] = s[i];
        for (int j = 0; j < blen; j++) {
            if (boom[blen - j - 1] == stack[top - j])cnt++;
            else break;
        }
        if (cnt == blen) top -= blen;
    }
    if (top <= 0) printf("FRULA");
    else {
        for (int i = 0; i <= top; i++) printf("%c", stack[i]);
    }
    return 0;
}