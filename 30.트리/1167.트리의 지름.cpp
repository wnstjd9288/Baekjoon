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
    Node* adj_list[100001];
}Graph;

// min : 둘 중 작은값을 리턴
int min(int a, int b) {
    return a < b ? a : b;
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
int max = -1;
int maxindex = 0;
int visited[100001] = { 0, };
void Mk_Tree(Graph* g, int now, int dist) {
    if (max < dist) {
        max = dist;
        maxindex = now;
    }
    visited[now] = 1;
    Node* i;
    for (i = g->adj_list[now]; i != NULL; i = i->next) {
        Data next = i->data;
        if (!visited[next.v]) {
            Mk_Tree(g, next.v, dist + next.w);
        }
    }
    visited[now] = 0;
}

int main() {
    int n;
    Graph* g = (Graph*)malloc(sizeof(Graph));
    scanf("%d", &n);
    init(g, n);
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        while (1) {
            int v, w;
            scanf("%d", &v);
            if (v == -1)break;
            scanf("%d", &w);
            push(g, u, v, w);
        }
    }
    //printlist(g);
    Mk_Tree(g, 1, 0);
    max = -1;
    Mk_Tree(g, maxindex, 0);
    printf("%d", max);

    return 0;
}