#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct grid1 {
    int u;
    int v;
    int w;
}Data;

typedef struct _Node {
    Data data;
    struct _Node* next;
}Node;

typedef struct Graph {
    int n;
    Node* adj_list[101];
}Graph;

typedef struct grid2 {
    int x;
    int y;
}Cod;

int min(int a, int b) {
    return a < b ? a : b;
}

void init(Graph* g, int n) {
    g->n = n;
    for (int i = 1; i <= n; i++) g->adj_list[i] = NULL;
}

void graph_push(Graph* g, int u, int v, int w) {

    Node* node = (Node*)malloc(sizeof(Node));
    node->data.v = v;
    node->data.w = w;
    node->next = g->adj_list[u];
    g->adj_list[u] = node;

}

void printlist(Graph* g) {
    for (int i = 1; i <= g->n; i++) {
        Node* p = g->adj_list[i];
        printf("%d ", i);
        while (p != NULL) {
            printf("-> %d,%lld ", p->data.v, p->data.w);
            p = p->next;
        }
        puts("");
    }
}

Data Heap[1000001];
int cnt = 0;

void Heap_push(Data x) {
    Heap[++cnt] = x;
    int child = cnt;
    int parent = child / 2;

    while (child > 1 && Heap[child].w < Heap[parent].w) {
        Data temp = Heap[child];
        Heap[child] = Heap[parent];
        Heap[parent] = temp;

        child = parent;
        parent = child / 2;
    }
}

Data Heap_pop() {

    Data remove = Heap[1];
    Heap[1] = Heap[cnt--];
    int parent = 1;
    int child = parent * 2;
    if (child + 1 <= cnt) {
        child = Heap[child].w < Heap[child + 1].w ? child : child + 1;
    }
    while (child <= cnt && Heap[child].w < Heap[parent].w) {
        Data temp = Heap[child];
        Heap[child] = Heap[parent];
        Heap[parent] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= cnt) {
            child = Heap[child].w < Heap[child + 1].w ? child : child + 1;
        }
    }
    return remove;
}

int visited[101] = { 0, };
long long weight_MST = 0;
void prim(Graph* g, int r) {

    Heap_push({ -1,r,0 });

    while (cnt > 0) {
        Data now = Heap_pop();
        if (visited[now.v]) continue;
        visited[now.v] = 1;
        weight_MST += now.w;
        Node* i;
        for (i = g->adj_list[now.v]; i; i = i->next) {
            Data next = i->data;
            if (!visited[next.v]) Heap_push(next);

        }
    }

}

int n, m;
int map[101][101];
int map_visited[101][101] = { 0, };
Cod que[100001];
Cod xy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
void BFS(Cod start,int num) {
    int h = -1, t = -1;
    que[++t] = start;
    while (h != t) {
        Cod now = que[++h];
        if (map_visited[now.x][now.y]) continue;
        map_visited[now.x][now.y] = num;
        for (int i = 0; i < 4; i++) {
            Cod next = now;
            next.x += xy[i].x;
            next.y += xy[i].y;
            if (next.x > n || next.x <= 0 || next.y > m || next.y <= 0) continue;
            if (!map[next.x][next.y] || map_visited[next.x][next.y]) continue;
            que[++t] = next;
        }
    }

}

Cod find_island(Cod now, int num, int k) {
    Cod next = { now.x + xy[k].x,now.y + xy[k].y };
    if (next.x > n || next.x <= 0 || next.y > m || next.y <= 0) return {0,0};
    if (map_visited[next.x][next.y] == num) return { 0,0 };
    if (map_visited[next.x][next.y]) return next;

    return find_island(next, num, k);
}

int main() {

    int count=0;
    int island[101][101] = { 0, };
    Graph* g = (Graph*)malloc(sizeof(Graph));
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] && !map_visited[i][j]) BFS({ i,j }, ++count);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map_visited[i][j]) {
                for (int k = 0; k < 4; k++) {
                    Cod line = find_island({ i,j }, map_visited[i][j], k);
                    if (!line.x) continue;
                    if (abs(line.x - i) + abs(line.y - j) - 1 < 2) continue;
                    if (island[map_visited[i][j]][map_visited[line.x][line.y]])
                        island[map_visited[i][j]][map_visited[line.x][line.y]] = min(island[map_visited[i][j]][map_visited[line.x][line.y]], abs(line.x - i) + abs(line.y - j) - 1);
                    else island[map_visited[i][j]][map_visited[line.x][line.y]] = abs(line.x - i) + abs(line.y - j) - 1;
                }
            }
        }
    }

    init(g, count);    
    for (int i = 1; i <= count; i++) {
        for (int j = i+1; j <= count; j++){
            if (island[i][j]) {
                graph_push(g, i, j, island[i][j]);
                graph_push(g, j, i, island[i][j]);
            }
        }
    }
    prim(g, 1);
    int sum = 0;
    for (int i = 1; i <= count; i++) sum += visited[i];
    if (sum == count) printf("%d", weight_MST);
    else printf("-1");
    return 0;
}