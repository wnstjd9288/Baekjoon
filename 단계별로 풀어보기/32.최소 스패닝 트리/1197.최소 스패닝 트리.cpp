#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int v;
    int w;
}Data;

typedef struct _Node {
    Data data;
    struct _Node* next;
}Node;

typedef struct Graph {
    int n;
    Node* adj_list[10001];
}Graph;

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
            printf("-> %d,%d ", p->data.v, p->data.w);
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

int visited[10001] = { 0, };
int weight_MST = 0;
void prim(Graph* g, int r) {

    Heap_push({ r,0 });

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

int main() {

    int n, m;
    Graph* g = (Graph*)malloc(sizeof(Graph));
    scanf("%d %d", &n, &m);
    init(g, n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph_push(g, u, v, w);
        graph_push(g, v, u, w);
    }
    prim(g, 1);
    printf("%d\n", weight_MST);
    return 0;
}