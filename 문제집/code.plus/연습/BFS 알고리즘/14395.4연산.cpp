#include <stdio.h>
#include <stdlib.h>
typedef struct Num {
    int data;
    int pos;
    int op;
}Num;
Num que[10000001];

void print_res(int res) {
    if (res <= 0) {
        if (res == -2) printf("0");
        if (res == -3) printf("-1");
        return;
    }
    print_res(que[res].pos);
    switch (que[res].op)
    {
    case 0:
        printf("*");
        break;
    case 1:
        printf("+");
        break;
    case 2:
        printf("/");
        break;
    }
}

int BFS(int start, int end) {
    if (start == end) return -2;
    int h = -1, t = -1;
    bool flag = true;
    que[++t] = { start,-1,-1 };
    while (h != t) {
        Num now = que[++h];
        if (now.data == end) return h;
        for (int i = 0; i < 3; i++) {
            Num next = now;
            next.op = i;
            next.pos = h;
            switch (i)
            {
            case 0:
                if (next.data == 1) continue;
                if (next.data >= 31623) continue;
                next.data *= next.data;
                break;
            case 1:
                if (next.data >= 500000001) continue;
                next.data *= 2;
                break;
            case 2:
                if (!flag) continue;
                next.data = 1;
                flag = false;
                break;
            }
            if (next.data > end) continue;
            que[++t] = next;
        }
    }
    return -3;
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    print_res(BFS(n, k));
    return 0;
}