#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Cod {
    int x;
    int y;
}Cod;

int n;
int map[101][101] = { 0, };
char turn[10001];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
Cod que[100001];

int Dummy() {
    int head = 0, tail = 0;
    int dir = 0;
    int time;
    que[head] = { 1,1 };
    for (time = 0;; time++) {
        Cod next = que[head];
        switch (turn[time]) {
        case 'D':
            dir++;
            dir %= 4;
            break;
        case 'L':
            dir--;
            if (dir < 0) dir += 4;
            break;
        default:
            break;
        }
        next.x += xy[dir].x;
        next.y += xy[dir].y;
        if (next.x > n || next.x <= 0 || next.y > n || next.y <= 0) return time + 1;
        for (int i = tail; i <= head; i++) {
            if (que[i].x == next.x && que[i].y == next.y) return time + 1;
        }
        que[++head] = next;
        if (!map[next.x][next.y]) tail++;
        else map[next.x][next.y] = 0;
    }
}

int main() {
    int k, l;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        int a;
        char c;
        scanf("%d %c", &a, &c);
        turn[a] = c;
    }
    printf("%d", Dummy());
    return 0;
}