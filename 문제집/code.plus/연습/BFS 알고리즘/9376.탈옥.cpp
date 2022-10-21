#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cod {
	int x;
	int y;
	int wall;
}Cod;

int n, m;
char map_char[103][103] = { 0, };
char map[103][103] = { 0, };
int visited[103][103][3] = { 0, };
Cod heap[1000001];
int cnt = 0;

void push(Cod x) {
    heap[++cnt] = x;
    int child = cnt;
    int parent = child / 2;

    while (child > 1 && heap[child].wall < heap[parent].wall) {
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
        child = heap[child].wall < heap[child + 1].wall ? child : child + 1;
    }
    while (child <= cnt && heap[child].wall < heap[parent].wall) {
        Cod temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= cnt) {
            child = heap[child].wall < heap[child + 1].wall ? child : child + 1;
        }
    }
    return r;
}

void cpy() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i + 1][j + 1] = map_char[i][j];
		}
	}
}

void init() {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            for (int k = 0; k < 3; k++) {
                visited[i][j][k] = 0;
            }
            map[i][j] = map_char[i][j] = 0;
        }
    }
}

Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
void BFS(Cod start, int num) {
    visited[start.x][start.y][num] = 1;
    push(start);
    while (cnt > 0) {
        Cod now = pop();
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x > n + 1 || next.y < 0 || next.y > m + 1) continue;
            if (map[next.x][next.y] == '*') continue;
            if (map[next.x][next.y] == '#') next.wall++;
            if (visited[next.x][next.y][num] && visited[next.x][next.y][num] <= next.wall) continue;
            visited[next.x][next.y][num] = next.wall;
            push(next);

        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++) {
        int cnt = 0;
        int min = 1e9;
        Cod list[3];
        scanf("%d %d", &n, &m);
        init();
        list[cnt++] = { 0,0,1 };
        for (int i = 0; i < n; i++) {
            scanf("%s", map_char[i]);
            for (int j = 0; j < m; j++) {
                if (map_char[i][j] == '$') list[cnt++] = { i + 1,j + 1,1 };
            }
        }
        cpy();
        for (int i = 0; i < 3; i++) {
            BFS(list[i], i);
        }
        for (int i = 0; i <= n+1; i++) {
            for (int j = 0; j <= m+1; j++) {
                if (!visited[i][j][0]) continue;

                int sum = 0;
                for (int k = 0; k < 3; k++) {
                    sum += visited[i][j][k] - 1;
                }
                if (map[i][j] == '#')sum -= 2;
                if (sum < min)min = sum;
            }
        }

        printf("%d\n", min);
    }
	return 0;
}