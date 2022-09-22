#include <stdio.h>

int mat1[101][101] = { 0, };
int mat2[101][101] = { 0, };
int res_mat[101][101] = { 0, };
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    int k;
    scanf("%d %d", &m, &k);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int p = 1; p <= m; p++) {
                res_mat[i][j] += mat1[i][p] * mat2[p][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            printf("%d ", res_mat[i][j]);
        }puts("");
    }

    return 0;
}