#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
    int move;
}Cod;
typedef struct MAP {
    int map[9][9] = { 0, };
}MAP;
int wall_cnt = 0;
Cod wall_list[65];
Cod que[1000001];
MAP visited[9];
Cod xy[9] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{0,0} };

bool check_wall(Cod next) {

    for (int i = 0; i < wall_cnt; i++) {
        if (wall_list[i].x + next.move >= 8) return false;
        if (next.x == wall_list[i].x + next.move && next.y == wall_list[i].y) return true;
    }
    return false;
}

bool BFS(Cod start) {
    int h = -1, t = -1;

    que[++t] = start;
    visited[start.move].map[start.x][start.y] = 1;
    while (h != t) {
        Cod now = que[++h];
        for (int i = 0; i < 9; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x == 0 && next.y == 7) return true;
            if (next.x < 0 || next.x >= 8 || next.y < 0 || next.y >= 8) continue;
            if (check_wall(next)) continue;
            if (next.move < 7) {
                next.move++;
                if (check_wall(next)) continue;
            }
            if (visited[next.move].map[next.x][next.y]) continue;
            visited[next.move].map[next.x][next.y] = 1;
            que[++t] = next;
        }
    }
    return false;
}

int main() {
    char map[9];
    for (int i = 0; i < 8; i++) {
        scanf("%s", map);
        for (int j = 0; j < 8; j++) {
            if (map[j] == '#') wall_list[wall_cnt++] = { i,j };
        }
    }
    if (BFS({ 7,0,0 })) printf("1");
    else printf("0");

    return 0;
}