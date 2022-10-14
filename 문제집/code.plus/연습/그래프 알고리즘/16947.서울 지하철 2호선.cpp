#include <stdio.h>
#include <stdlib.h>
typedef struct _Node {
    int data;
    struct _Node* next;
}Node;

typedef struct Graph {
    int n;
    Node* adj_list[3001];
}Graph;

void init(Graph* g, int n) {
    g->n = n;
    for (int i = 1; i <= n; i++) g->adj_list[i] = NULL;
}

void push(Graph* g, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = v;
    node->next = g->adj_list[u];
    g->adj_list[u] = node;
}

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

int visited[3001] = { 0, };
int res = -1;
void DFS(Graph* g, int now, int prev,int cnt) {
    visited[now] = cnt;
    Node* i;
    for (i = g->adj_list[now]; i; i = i->next) {
        if (i->data == prev) continue;

        if (visited[i->data]) {
            res = visited[i->data];
            return;
        }
        else DFS(g, i->data, now, cnt + 1);
        if (res != -1) return;
    }
}

int main() {
    int n;
    Graph* g = (Graph*)malloc(sizeof(Graph));
    scanf("%d", &n);
    init(g, n);
    for (int i = 0; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push(g, u, v);
        push(g, v, u);
    }
    //printlist(g);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) visited[j] = 0;
        res = -1;
        DFS(g, i, -1, 1);
        printf("%d ", res-1);
    }
    return 0;
}