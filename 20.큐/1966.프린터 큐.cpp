#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int pri;
    int index;
}File;

int f(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int main() {

    int k;
    scanf("%d", &k);

    for (int test = 0; test < k; test++) {

        int n, m;
        File file[101], q[100001] = { 0, };
        int pri[101];
        int h = 0, t = -1;
        int now = 0;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            scanf("%d", &file[i].pri);
            file[i].index = i;
            q[++t] = file[i];
            pri[i] = file[i].pri;
        }
        qsort(pri, n, sizeof(int), f);

        while (h != t) {

            if (q[h].pri != pri[now]) {
                q[++t] = q[h++];
            }
            else {
                if (q[h].index == m) break;
                h++;
                now++;
            }
        }
        printf("%d\n", now + 1);
    }
    return 0;
}