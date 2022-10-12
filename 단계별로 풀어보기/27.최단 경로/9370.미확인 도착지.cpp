#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int v;
    int w;
}Data;

typedef struct _Node {
    Data data;
    struct _Node* next;
}Node;

// Graph : 인접 리스트
typedef struct Graph {
    int n;
    Node* adj_list[20001];
}Graph;

// min : 둘 중 작은값을 리턴
int min(int a, int b) {
    return a < b ? a : b;
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// init : 초기화 함수
void init(Graph* g, int n) {
    g->n = n;
    for (int i = 1; i <= n; i++) g->adj_list[i] = NULL;
}

// push : 인접리스트 삽입 함수
void push(Graph* g, int u, int v, int w) {

    Node* node = (Node*)malloc(sizeof(Node));
    node->data.v = v;
    node->data.w = w;
    node->next = g->adj_list[u];
    g->adj_list[u] = node;

}

// printlist : 인접 리스트 출력 함수
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

int history[2001] = { 0, };
int check[2001] = { 0, };
int weight[2001];
Data heap[200001];
int cnt = 0;
int h1, h2;
// Heap_push : heap에 데이터를 추가하는 함수
void Heap_push(Data x) {
    heap[++cnt] = x;
    int child = cnt;
    int parent = child / 2;

    while (child > 1 && heap[child].w < heap[parent].w) {
        Data temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        child = parent;
        parent = child / 2;
    }
}
// pop : heap의 top을 배열에서 지우며 리턴해주는 함수
Data pop() {

    Data r = heap[1];
    heap[1] = heap[cnt];
    cnt--;
    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= cnt) {
        child = heap[child].w < heap[child + 1].w ? child : child + 1;
    }
    while (child <= cnt && heap[child].w < heap[parent].w) {
        Data temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= cnt) {
            child = heap[child].w < heap[child + 1].w ? child : child + 1;
        }
    }
    return r;
}
// Dijkstra : 최소 거리 탐색 함수
void Dijkstra(Graph* g, int r) {

    int c = 0;
    Data start = { r,0 };
    weight[r] = 0;
    Heap_push(start);
    while (cnt > 0) {
        Data now = pop();
        Node* i;
        if (weight[now.v] < now.w) continue;
        for (i = g->adj_list[now.v]; i; i = i->next) {
            if (weight[i->data.v] > weight[now.v] + i->data.w) {
                weight[i->data.v] = weight[now.v] + i->data.w;
                if (!check[now.v]) check[i->data.v] = 0;
                else check[i->data.v] = 1;
                if (i->data.v == h1 && now.v == h2 || i->data.v == h2 && now.v == h1) {
                    check[i->data.v] = 1;
                }
                history[i->data.v] = now.v;
                Heap_push(i->data);
            }
            else if (weight[i->data.v] == weight[now.v] + i->data.w) {
                if (i->data.v == h1 && now.v == h2 || i->data.v == h2 && now.v == h1 || !check[i->data.v] && check[now.v]) {
                    weight[i->data.v] = weight[now.v] + i->data.w;
                    history[i->data.v] = now.v;
                    check[i->data.v] = 1;
                    Heap_push(i->data);
                }
            }
        }
    }
}

int main() {
    int test;
    scanf("%d", &test);
    for (int k = 0; k < test; k++) {
        int n, m, t;
        int r;
        Graph* g = (Graph*)malloc(sizeof(Graph));
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &r, &h1, &h2);
        for (int i = 0; i <= n; i++) {
            history[i] = check[i] = 0;
        }
        init(g, n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            push(g, u, v, w);
            push(g, v, u, w);
        }
        for (int i = 1; i <= n; i++) {
            weight[i] = 1e8;
        }
        Dijkstra(g, r);
        int list[101] = { 0, };
        for (int i = 0; i < t; i++) {
            scanf("%d", &list[i]);
        }
        //printlist(g);
        qsort(list, t, sizeof(int), cmp);
        for (int i = 0; i < t; i++) {
            if (check[list[i]]) printf("%d ", list[i]);
        }puts("");

        free(g);
    }

    return 0;
}