#include <stdio.h>

long long int mat1[5][5] = { 0, };
long long int res_mat[5][5] = { 0, };
long long int b;
int n;

void mul(long long int X[5][5], long long int Y[5][5]) {
    int result[5][5] = { 0, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += X[i][k] * Y[k][j];
                result[i][j] %= 1000;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) X[i][j] = result[i][j];
}

int main() {
    scanf("%d %lld", &n, &b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &mat1[i][j]);
            res_mat[i][j] = mat1[i][j];
        }
    }
    b--;
    while (b > 0) {
        if (b % 2 == 0) {
            mul(mat1, mat1);
            b /= 2;
            continue;
        }
        else mul(res_mat, mat1);
        b--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lld ", res_mat[i][j] % 1000);
        }puts("");
    }
    return 0;
}