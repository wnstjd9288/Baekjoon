#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
    int n;
    int A[1001];
    int LTS1[1001];
    int LTS2[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", &A[i]);
    LTS1[0] = 1;
    for (int i = 1; i < n; i++) {
        LTS1[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) LTS1[i] = max(LTS1[i], LTS1[j] + 1);
        }
    }
    LTS2[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        LTS2[i] = 1;
        for (int j = i; j < n; j++) {
            if (A[i] > A[j]) LTS2[i] = max(LTS2[i], LTS2[j] + 1);
        }
    }
    int m = -1;
    for (int i = 0; i < n; i++) {
        m = max(m, LTS1[i] + LTS2[i]);
    }
    printf("%d", m - 1);
    return 0;
}