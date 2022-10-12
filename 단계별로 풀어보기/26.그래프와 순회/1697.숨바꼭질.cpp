#include <stdio.h>
#include <stdlib.h>

int que[10000001] = { 0, };
int visited[10000001] = { 0, };
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int h = -1, t = -1;
    que[++t] = n;
    visited[n] = 1;
    while (h != t) {
        int now = que[++h];
        if (now == k)break;
        for (int i = 0; i < 3; i++) {
            int next = now;
            if (i == 0) next--;
            else if (i == 1) next++;
            else if (i == 2) next *= 2;
            if (next < 0 || next >= 1000000)continue;
            if (visited[next] == 0 || visited[next] > visited[now] + 1) {
                visited[next] = visited[now] + 1;
                que[++t] = next;
            }
        }
    }
    printf("%d", visited[k] - 1);
    return 0;
}