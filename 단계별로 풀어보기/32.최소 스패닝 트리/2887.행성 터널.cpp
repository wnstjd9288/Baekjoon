#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct grid {
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
    Node* adj_list[1000001];
}Graph;

typedef struct Planet {
    int x;
    int y;
    int z;
    int index;
}Planet;

int min(int a, int b) {
    return a < b ? a : b;
}

int cmp_x(const void* a, const void* b) {
    Planet x = *(Planet*)a;
    Planet y = *(Planet*)b;
    return x.x - y.x;
}
int cmp_y(const void* a, const void* b) {
    Planet x = *(Planet*)a;
    Planet y = *(Planet*)b;
    return x.y - y.y;
}
int cmp_z(const void* a, const void* b) {
    Planet x = *(Planet*)a;
    Planet y = *(Planet*)b;
    return x.z - y.z;
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

int visited[100001] = { 0, };
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

Planet planet[100001];
int main() {

    int n, m;
    Graph* g = (Graph*)malloc(sizeof(Graph));
    scanf("%d", &n);
    init(g, n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &planet[i].x, &planet[i].y, &planet[i].z);
        planet[i].index = i + 1;
    }
    qsort(planet, n, sizeof(Planet), cmp_x);
    for (int i = 1; i < n; i++) {
        graph_push(g, planet[i - 1].index, planet[i].index, abs(planet[i].x - planet[i - 1].x));
        graph_push(g, planet[i].index, planet[i - 1].index, abs(planet[i].x - planet[i - 1].x));
    }
    qsort(planet, n, sizeof(Planet), cmp_y);
    for (int i = 1; i < n; i++) {
        graph_push(g, planet[i - 1].index, planet[i].index, abs(planet[i].y - planet[i - 1].y));
        graph_push(g, planet[i].index, planet[i - 1].index, abs(planet[i].y - planet[i - 1].y));
    }
    qsort(planet, n, sizeof(Planet), cmp_z);
    for (int i = 1; i < n; i++) {
        graph_push(g, planet[i - 1].index, planet[i].index, abs(planet[i].z - planet[i - 1].z));
        graph_push(g, planet[i].index, planet[i - 1].index, abs(planet[i].z - planet[i - 1].z));
    }
    //printlist(g);
    prim(g, 1);
    printf("%lld\n", weight_MST);
    return 0;
}