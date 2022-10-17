#include <stdio.h>
#include <stdlib.h>

typedef struct Stone {
    int x;
    int y;
    int z;
}Stone;
int visited[1501][1501] = { 0, };
Stone que[1000001];
void BFS(Stone start, int sum) {
    int h = -1, t = -1;
    que[++t] = start;
    while (h != t) {
        Stone now = que[++h];
        if (now.x == now.y && now.y == now.z) {
            printf("1");
            return;
        }
        if (visited[now.x][now.y]) continue;
        visited[now.x][now.y] = 1;
        int stone[3] = { now.x,now.y,sum - (now.x + now.y) };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (stone[i] < stone[j]) {
                    int n1 = stone[i] * 2;
                    int n2 = stone[j] - stone[i];
                    if (!visited[n1][n2]) que[++t] = { n1,n2,sum - (n1 + n2) };
                }
            }
        }
    }
    printf("0");
}

int main() {

    int sum = 0;
    Stone stone;
    scanf("%d %d %d", &stone.x, &stone.y, &stone.z);
    sum = stone.x + stone.y + stone.z;
    if (sum % 3) {
        printf("0");
        return 0;
    }
    BFS(stone, sum);
    return 0;
}