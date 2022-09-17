#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b) {
    return a > b ? a : b;
}
char A[1001], B[1001];
int map[1001][1001] = { 0, };
int main() {

    int Alen, Blen;
    scanf("%s", A);
    scanf("%s", B);
    Alen = strlen(A);
    Blen = strlen(B);
    for (int i = 1; i <= Alen; i++) {
        for (int j = 1; j <= Blen; j++) {
            if (A[i - 1] == B[j - 1])map[i][j] = map[i - 1][j - 1] + 1;
            else map[i][j] = max(map[i - 1][j], map[i][j - 1]);
        }
    }
    printf("%d", map[Alen][Blen]);
    return 0;
}