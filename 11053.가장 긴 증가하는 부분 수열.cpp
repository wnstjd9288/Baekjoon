#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
    int n;
    int A[1001];
    int LTS[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", &A[i]);
    LTS[0] = 1;
    for (int i = 1; i < n; i++) {
        LTS[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) LTS[i] = max(LTS[i], LTS[j] + 1);
        }
    }
    int max = -1;
    for (int i = 0; i < n; i++) if (max < LTS[i])max = LTS[i];
    printf("%d", max);
    return 0;
}