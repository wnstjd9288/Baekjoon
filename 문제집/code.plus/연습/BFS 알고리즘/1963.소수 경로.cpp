#include <stdio.h>
#include <stdlib.h>
bool prime[10001] = { 0, };
int visited[10001] = { 0, };
int que[10000001];
int BFS(int start, int end) {
    if (start == end) return 0;
    int h = -1, t = -1;
    visited[start] = 1;
    que[++t] = start;
    while (h != t) {
        int now = que[++h];
        for (int i = 0; i < 4; i++) {
            int d = 1;
            for (int j = 0; j < i; j++) d *= 10;
            for (int j = 0; j < 10; j++) {
                int next = now;
                next = next - next % (d * 10) + next % d + j * d;
                if (next < 1000) continue;
                if (prime[next]) continue;
                if (visited[next] && visited[next] <= visited[now] + 1) continue;
                if (next == end) return visited[now];
                visited[next] = visited[now] + 1;
                que[++t] = next;
            }
        }
    }
    return -1;
}

int main() {

    prime[0] = prime[1] = true;
    for (int i = 2; i <= 5000; i++) {
        if (!prime[i]) {
            for (int j = i*2; j <= 9999; j+=i) {
                prime[j] = true;
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < 10000; i++)visited[i] = 0;
        int res = BFS(n, k);
        if (res >= 0) printf("%d\n", res);
        else printf("Impossible\n");
    }

    return 0;
}