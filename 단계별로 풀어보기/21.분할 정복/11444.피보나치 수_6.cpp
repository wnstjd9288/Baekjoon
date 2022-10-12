#include <stdio.h>

long long int pibo_mat[2][2] = { {1,1}, {1,0} };
long long int unit_mat[2][2] = { {1,1}, {1,0} };

void pibo(long long int X[2][2], long long int Y[2][2]) {
    long long int res[2][2] = { 0, };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] += X[i][k] * Y[k][j];
                res[i][j] %= 1000000007;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            X[i][j] = res[i][j];
        }
    }
}

int main() {
    long long int n;
    scanf("%lld", &n);
    n -= 2;
    while (n > 0) {
        if (n % 2 == 0) {
            pibo(unit_mat, unit_mat);
            n /= 2;
        }
        else {
            pibo(pibo_mat, unit_mat);
            n--;
        }
    }
    printf("%lld", pibo_mat[0][0]);

    return 0;
}