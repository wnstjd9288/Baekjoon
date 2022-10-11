#include <stdio.h>
#include <stdlib.h>

typedef struct Cod {
    int x;
    int y;
    int wall;
}Cod;

Cod heap[10000001] = { 0, };
int cnt = 0;

void push(Cod x) {
    heap[++cnt] = x;
    int child = cnt;
    int parent = child / 2;

    while (child > 1 && heap[child].wall <= heap[parent].wall) {
        if (heap[child].wall == heap[parent].wall) {
            if (heap[child].x + heap[child].y <= heap[parent].x + heap[parent].y) break;
        }
        Cod temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        child = parent;
        parent = child / 2;
    }
}
Cod pop() {
    Cod r = heap[1];
    heap[1] = heap[cnt];
    cnt--;
    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= cnt) {
        if (heap[child].wall >= heap[child + 1].wall) {
            if (heap[child].wall == heap[child + 1].wall) {
                if (heap[child].x + heap[child].y < heap[child + 1].x + heap[child + 1].y) child++;
            }
            else child++;
        }
    }
    while (child <= cnt && heap[child].wall <= heap[parent].wall) {
        if (heap[child].wall == heap[parent].wall) {
            if (heap[child].x + heap[child].y <= heap[parent].x + heap[parent].y) break;
        }
        Cod temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= cnt) {
            if (heap[child].wall >= heap[child + 1].wall) {
                if (heap[child].wall == heap[child + 1].wall) {
                    if (heap[child].x + heap[child].y < heap[child + 1].x + heap[child + 1].y) child++;
                }
                else child++;
            }
        }
    }
    return r;
}

int n, m;
int map[1001][1001];
int visited[1001][1001] = { 0, };
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
void BFS() {
    push({ 0,0,0 });
    while (cnt > 0) {
        Cod now = pop();
        if (visited[now.x][now.y] && visited[now.x][now.y] <= now.wall + 1) continue;
        visited[now.x][now.y] = now.wall + 1;
        if (now.x == n && now.y == m) return;
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
            if (!visited[next.x][next.y] || visited[next.x][next.y] > next.wall + 1) {
                if (map[next.x][next.y]) push({ next.x,next.y,next.wall + 1 });
                else push({ next.x,next.y,next.wall });
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    BFS();
    printf("%d", visited[m - 1][n - 1] - 1);
    return 0;
}