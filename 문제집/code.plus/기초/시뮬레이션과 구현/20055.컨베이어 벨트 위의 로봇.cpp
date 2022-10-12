#include <stdio.h>
#include <stdlib.h>

typedef struct Conveyor {
    int HP;
    bool robot = false;
}Conveyor;

int n, k;
void rotate(Conveyor con[]) {
    Conveyor temp = con[n * 2];
    for (int i = n * 2; i >= 2; i--) {
        con[i] = con[i - 1];
        if (i >= n) con[i].robot = false;
    }
    con[1] = temp;
}

int main() {
    Conveyor con[201];
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n * 2; i++) {
        scanf("%d", &con[i].HP);
    }
    int res;
    for (res = 1;; res++) {
        rotate(con);
        for (int i = n; i >= 2; i--) {
            if (con[i - 1].robot && !con[i].robot && con[i].HP) {
                con[i - 1].robot = false;
                con[i].HP--;
                con[i].robot = true;
            }
        }
        if (con[1].HP) {
            con[1].robot = true;
            con[1].HP--;
        }
        int cnt = 0;
        for (int i = 1; i <= n * 2; i++) {
            if (!con[i].HP)cnt++;
        }
        if (cnt >= k)break;
    }
    printf("%d", res);
    return 0;
}