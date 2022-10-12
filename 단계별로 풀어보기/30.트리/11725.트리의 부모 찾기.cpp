#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int v;
    int w;
}Data;

typedef struct _Node {
    int data;
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
void push(Graph* g, int u, int v) {

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = v;
    node->next = g->adj_list[u];
    g->adj_list[u] = node;

}

// printlist : 인접 리스트 출력 함수
void printlist(Graph* g) {
    for (int i = 1; i <= g->n; i++) {
        Node* p = g->adj_list[i];
        printf("%d ", i);
        while (p != NULL) {
            printf("-> %d ", p->data);
            p = p->next;
        }
        puts("");
    }
}

int parent[100001] = { 0, };
int que[200001];

void Mk_Tree(Graph* g, int start) {
    int h = -1, t = -1;
    que[++t] = start;
    parent[start] = -1;
    while (h != t) {
        int now = que[++h];
        Node* i;
        for (i = g->adj_list[now]; i != NULL; i = i->next) {
            int next = i->data;
            if (!parent[next]) {
                parent[next] = now;
                que[++t] = next;
            }
        }
    }
}

int main() {
    int n;
    Graph* g = (Graph*)malloc(sizeof(Graph));
    scanf("%d", &n);
    init(g, n);
    for (int i = 0; i < n-1 ; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push(g, u, v);
        push(g, v, u);
    }
    //printlist(g);
    Mk_Tree(g, 1);
    for (int i = 2; i <= n; i++) {
        printf("%d\n", parent[i]);
    }
    return 0;
}