#include <stdio.h>
#include <stdlib.h>
typedef struct Cod {
    int x;
    int y;
}Cod;

int visited[6][6];
int map[6][6];
int dice[6];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };

void turn(int k) {
    int temp;
    switch (k)
    {
    case 0:
        temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[2];
        dice[2] = dice[4];
        dice[4] = temp;
        break;
    case 1:
        temp = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
        break;
    case 2:
        temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[5];
        dice[5] = temp;
        break;
    case 3:
        temp = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[0];
        dice[0] = dice[3];
        dice[3] = temp;
        break;
    }
    dice[0] = 1;
}

void DFS(Cod now) {

    for (int i = 0; i < 4; i++) {
        Cod next = now;
        next.x += xy[i].x;
        next.y += xy[i].y;
        if (next.x < 0 || next.x >= 6 || next.y < 0 || next.y >= 6) continue;
        if (!map[next.x][next.y] || visited[next.x][next.y]) continue;
        visited[next.x][next.y] = 1;
        turn(i);
        DFS(next);
        turn((i + 2) % 4);
    }

}

bool check() {
    for (int i = 0; i < 6; i++) {
        if (!dice[i]) return false;
    }
    return true;
}

int main() {

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                scanf("%d", &map[i][j]);
                visited[i][j] = 0;
            }
            dice[i] = 0;
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] && !visited[i][j]) {
                    visited[i][j] = 1;
                    dice[0] = 1;
                    DFS({ i,j });
                }
            }
        }
        if (check()) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}