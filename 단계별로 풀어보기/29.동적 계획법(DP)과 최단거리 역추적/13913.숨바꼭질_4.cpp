 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct grid {
    int value;
    int prev;
}box;
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
box h[1000001] = { 0, };
int que[1000001];
void print_res(int k) {
    if (k == -1)return;
    print_res(h[k].prev);
    printf("%d ", k);
}
int main() {
    int n, k;
    int head = -1, tail = -1;
    scanf("%d %d", &n, &k);
    
    que[++tail] = n;
    h[n].value = 1;
    h[n].prev = -1;
    while (head != tail) {
        int now = que[++head];
        if (now == k)break;
        for (int i = 0; i < 3; i++) {
            int next = now;
            if (i == 0) next--;
            else if (i == 1) next++;
            else if (i == 2) next *= 2;
            if (next < 0 || next >= 1000000)continue;
            if (h[next].value == 0 || h[next].value > h[now].value + 1) {
                h[next].value = h[now].value + 1;
                h[next].prev = now;
                que[++tail] = next;
            }
        }
    }
    printf("%d\n", h[k].value-1);
    print_res(k);
    return 0;
}