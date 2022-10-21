#include <stdio.h>
#include <stdlib.h>

int F, U, D;
int visited[1000001] = { 0, };
int que[10000001];

int BFS(int start, int end) {
    if (start == end) return 0;
    int h = -1, t = -1;
    visited[start] = 1;
    que[++t] = start;
    
    while (h != t) {
        int now = que[++h];
        for (int i = 0; i < 2; i++) {
            int next = now;
            switch (i)
            {
            case 0:
                if (now - D >= end) continue;
                next += U;
                break;
            case 1:
                if (now + U <= end) continue;
                next -= D;
                break;
            }
            if (next > F || next <= 0) continue;
            if (visited[next] && visited[next] <= visited[now] + 1) continue;
            if (next == end) return visited[now];
            visited[next] = visited[now] + 1;
            que[++t] = next;

        }
    }
    return -1;
}
int main() {
    int S, G;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    int res = BFS(S, G);
    if (res < 0) printf("use the stairs");
    else printf("%d", res);

    return 0;
}