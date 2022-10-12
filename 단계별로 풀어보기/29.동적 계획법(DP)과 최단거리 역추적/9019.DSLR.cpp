 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grid {
    int value;
    int prev;
    char prev_C;
}box;


void print_res(int k, box his[]) {
    if (his[k].prev == -1) return;
    print_res(his[k].prev, his);
    printf("%c", his[k].prev_C);
}

int main() {

    int a;
    scanf("%d", &a);
    for (int test = 0; test < a; test++) {
        int n, k;
        int h = -1, t = -1;
        box his[10001] = { 0, };
        int que[100001];
        scanf("%d %d", &n, &k);

        que[++t] = n;
        his[n] = { 1,-1,-1 };
        while (h != t) {
            int now = que[++h];
            if (now == k) break;
            int next = (now * 2) % 10000;
            if (!his[next].value || his[next].value > his[now].value + 1) {
                his[next].value = his[now].value + 1;
                his[next].prev = now;
                his[next].prev_C = 'D';
                que[++t] = next;
            }

            next = now - 1;
            if (next < 0) next += 10000;
            if (!his[next].value || his[next].value > his[now].value + 1) {
                his[next].value = his[now].value + 1;
                his[next].prev = now;
                his[next].prev_C = 'S';
                que[++t] = next;
            }

            next = (now % 1000) * 10 + now / 1000;
            if (!his[next].value || his[next].value > his[now].value + 1) {
                his[next].value = his[now].value + 1;
                his[next].prev = now;
                his[next].prev_C = 'L';
                que[++t] = next;
            }

            next = (now % 10) * 1000 + (now / 10);
            if (!his[next].value || his[next].value > his[now].value + 1) {
                his[next].value = his[now].value + 1;
                his[next].prev = now;
                his[next].prev_C = 'R';
                que[++t] = next;
            }

        }
        print_res(k, his);
        puts("");
    }

 
    return 0;
}