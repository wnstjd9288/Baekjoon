#include <stdio.h>
#include <stdlib.h>

void sort(int* A, int* B, int n) {
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[index]) {
                index = j;
            }

            if (j == n - 1) {
                //swap both A and B
                int temp = A[index];
                A[index] = A[i];
                A[i] = temp;

                temp = B[index];
                B[index] = B[i];
                B[i] = temp;
            }
        }
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    int m = -1;
    int map[501][501] = { 0, };
    int A[101], B[101];
    int LTS[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }
    sort(A, B, n);
    LTS[0] = 1;
    for (int i = 1; i < n; i++) {
        LTS[i] = 1;
        for (int j = 0; j <= i; j++) {
            if (B[i] > B[j]) LTS[i] = max(LTS[i], LTS[j] + 1);
        }
        if (LTS[i] > m)m = LTS[i];
    }
    if (n == 1) m = 1;
    printf("%d", n - m);
    return 0;
}