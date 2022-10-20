#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
}Cod;
typedef struct Shark {
    Cod cod;
    int size;
    int fish;
};

int n;
int ans = 0;
int map[21][21];
int dist[21][21] = { 0, };
int visited[21][21] = { 0, };
Cod que[1000001];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };

void BFS(Cod start,int size) {
    int h = -1, t = -1;
    que[++t] = start;
    visited[start.x][start.y] = 1;
    while (h != t) {
        Cod now = que[++h];
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) continue;
            if (visited[next.x][next.y] || map[next.x][next.y] > size) continue;
            if (map[next.x][next.y] && map[next.x][next.y] < size) dist[next.x][next.y] = visited[now.x][now.y];
            visited[next.x][next.y] = visited[now.x][now.y] + 1;
            que[++t] = next;
        }
    }
}

bool move_shark(Shark &s) {
    Cod index;
    int min_dist = 401;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dist[i][j] = visited[i][j] = 0;
    BFS(s.cod, s.size);
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (dist[i][j] && dist[i][j] <= min_dist) {
                index = { i,j };
                min_dist = dist[i][j];
            }
    
    if (min_dist == 401) return false;
    ans += min_dist;
    map[index.x][index.y] = 0;
    s.cod = index;
    if (s.fish + 1 == s.size) {
        s.size++;
        s.fish = 0;
    }
    else s.fish++;
    return true;

}

int main() {
    Shark s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) {
                map[i][j] = 0;
                s = { {i,j},2,0 };
            }
        }
    }
    while (move_shark(s));
    printf("%d", ans);
    return 0;
}