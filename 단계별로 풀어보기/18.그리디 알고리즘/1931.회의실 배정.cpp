#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int start;
    int end;
}Time;

int f(const void* a, const void* b) {
    Time x = *(Time*)a;
    Time y = *(Time*)b;

    if (x.end > y.end) return 1;
    else if (x.end == y.end) {
        if (x.start > y.start) return 1;
        else return -1;
    }
    else return -1;

}

int main() {

    int n;
    Time t[100001];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i].start, &t[i].end);
    }
    qsort(t, n, sizeof(Time), f);
    int cnt = 1;
    int time = t[0].end;
    for (int i = 1; i < n; i++) {
        if (t[i].start >= time) {
            time = t[i].end;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}