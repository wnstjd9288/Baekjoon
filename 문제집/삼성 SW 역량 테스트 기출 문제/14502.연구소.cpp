#include <stdio.h>
#include <stdlib.h>

typedef struct Cod {
    int x;
    int y;
}Cod;

int n, m;
int max = -1;
int cnt = -1;
int map[9][9] = { 0, };
int map_cpy[9][9];
Cod wall_list[101];
Cod wall[3];

void DFS(Cod now) {
    if (now.x < 0 || now.x >= n || now.y < 0 || now.y >= m) return;
    if (map_cpy[now.x][now.y]) return;
    map_cpy[now.x][now.y] = 1;
    DFS({ now.x + 1,now.y });
    DFS({ now.x,now.y + 1 });
    DFS({ now.x - 1,now.y });
    DFS({ now.x,now.y - 1 });
}

void select_wall(int c, int start) {
    
    if (c == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map_cpy[i][j] = map[i][j];
                if (map[i][j] == 2) map_cpy[i][j] = 0;
            }
        }
        for (int i = 0; i < 3; i++) map_cpy[wall[i].x][wall[i].y] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 2) DFS({ i,j });
            }
        }
        int safezone = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map_cpy[i][j] == 0) safezone++;
            }
        }
        if (safezone > max) max = safezone; 
        return;
    }

    for (int i = start; i <= cnt - 2 + c; i++) {
        wall[c] = wall_list[i];
        select_wall(c + 1, i + 1);

    }

}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]==0) wall_list[++cnt] = { i,j };
        }
    }
    select_wall(0, 0);
    printf("%d", max);
    return 0;
}