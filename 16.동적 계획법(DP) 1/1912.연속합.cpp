#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    int s[100001];
    int m[100001] = { 0, };
    int max = -9999;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    m[0] = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] < s[i] + m[i - 1]) m[i] = s[i] + m[i - 1];
        else m[i] = s[i];
        if (max < m[i])max = m[i];
    }
    if (m[0] > max)max = m[0];
    printf("%d", max);
    return 0;
}