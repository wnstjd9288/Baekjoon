#include <stdio.h>
#include <stdlib.h>

int q[10000001];
int yo[1001] = { 0, };
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int t = 0;
    int h = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        q[++t] = i + 1;
    }

    while (h != t) {
        if (h % k == 0) {
            yo[cnt++] = q[h++];
        }
        else {
            q[++t] = q[h++];
        }
    }
    yo[cnt] = q[h];
    printf("<%d", yo[0]);
    for (int i = 1; i <= cnt; i++) {
        printf(", %d", yo[i]);
    }printf(">");
    return 0;
}