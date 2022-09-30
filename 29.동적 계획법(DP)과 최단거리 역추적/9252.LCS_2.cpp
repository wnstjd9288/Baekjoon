#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct grid {
    int x;
    int y;
}cod;
int max(int a, int b) {
    return a > b ? a : b;
}
char A[1001], B[1001];
int map[1001][1001] = { 0, };
cod history[1001][1001] = { 0, };
void print_res(cod start, int len) {
    if (len <= 0) return;
    for (cod i = start; i.x != 0 && i.y != 0; i = history[i.x][i.y]) {
        int next = i.x + i.y - (history[i.x][i.y].x + history[i.x][i.y].y);
        if (next == 2) {
            print_res(history[i.x][i.y], len - 1);
            printf("%c", A[history[i.x][i.y].x]);
            return;
        }
    }
}
int main() {

    int Alen, Blen;
    scanf("%s", A);
    scanf("%s", B);
    Alen = strlen(A);
    Blen = strlen(B);
    for (int i = 1; i <= Alen; i++) {
        for (int j = 1; j <= Blen; j++) {
            if (A[i - 1] == B[j - 1]) { 
                map[i][j] = map[i - 1][j - 1] + 1; 
                history[i][j] = { i - 1,j - 1 };
            }
            else {
                map[i][j] = max(map[i - 1][j], map[i][j - 1]); 
                if (map[i][j] == map[i - 1][j]) {
                    history[i][j] = { i - 1,j };
                }
                else history[i][j] = { i,j - 1 };
            }
        }
    }
    printf("%d\n", map[Alen][Blen]);
    print_res({ Alen,Blen }, map[Alen][Blen]);
    return 0;
}