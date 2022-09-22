#include <stdio.h>
#include <stdlib.h>
int q[10000001] = { 0, };
int main() {
    int n;
    scanf("%d", &n);

    int h = 0;
    int t = -1;
    for (int i = 0; i < n; i++) q[++t] = i + 1;
    while (h != t) {
        h++;
        if (h == t) break;
        q[++t] = q[h++];

    }
    printf("%d", q[t]);
    return 0;
}