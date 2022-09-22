#include <stdio.h>
#include <stdlib.h>

int que[100001] = { 0, };
int visited[101] = { 0, };
int map[101] = { 0, };
int main() {

    int n, m;
    int h = -1, t = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a] = b;
    }
    que[++t] = 1;
    while (h != t) {
        int now = que[++h];
        if (now == 100)break;
        for (int i = 1; i <= 6; i++) {
            int next = now + i;
            if (next > 100) break;
            if (map[next]) next = map[next];
            if (!visited[next] || visited[next] > visited[now] + 1) {
                visited[next] = visited[now] + 1;
                que[++t] = next;
            }
        }
    }
    printf("%d", visited[100]);
    return 0;
}