#include <stdio.h>
#include <stdlib.h>
int main() {

    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
        }
        printf("%d\n", n - 1);
    }
    return 0;
}