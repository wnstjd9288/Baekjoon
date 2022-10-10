#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int data;
    int time;
    int board;
}Data;

Data que[1000001];
int visited[1001] = { 0, };

void BFS(int n) {
    int h = -1, t = -1;
    que[++t] = { 1,1,1 };
    while (h != t) {
        Data now = que[++h];
        visited[now.data] = now.time;
        if (now.data == n) return;
        Data next = now;
        next.data += next.board;
        next.time++;
        if (!visited[next.data] || visited[next.data] > next.time) que[++t] = next;

        next = now;
        next.data--;
        next.time++;
        if(next.data>=0)
            if (!visited[next.data] || visited[next.data] > next.time) que[++t] = next;

        next = now;
        next.board = next.data;
        next.time++;
        if (now.board != next.board) que[++t] = next;

    }

}

int main() {
    int n;
    scanf("%d", &n);
    BFS(n);
    printf("%d", visited[n]);
    return 0;
}