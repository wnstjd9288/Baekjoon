#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
int result = 0;
int board[15];
int check(int num) {

    for (int i = 0; i < num; i++) {
        if (board[i] == board[num] || (num - i) == abs(board[i] - board[num])) return 0;
    }
    return 1;
}
void chess(int lev) {

    if (lev == n) {
        result++;
        return;
    }
    for (int i = 0; i < n; i++) {
        board[lev] = i;
        if (check(lev)) chess(lev + 1);
    }
}


int main() {

    scanf("%d", &n);
    chess(0);
    printf("%d", result);
    return 0;
}