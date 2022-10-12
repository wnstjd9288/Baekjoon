#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
}Node;

// Graph : 인접 리스트
typedef struct Graph {
    int n;
    Node* adj_list[100001];
}Graph;

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

int visited[100001];
int cnt;
bool flag = false;
int cycle;
// DFS : 깊이 우선 탐색 함수
void DFS(Graph* g, int r, int prev) {

    visited[r] = cnt;
    Node* i;
    for (i = g->adj_list[r]; i; i = i->next) {
        if (!visited[i->data]) {
            DFS(g, i->data, r);
        }
        else {
            if (i->data != prev) flag = true;
        }
    }
}

int main() {
    for (int test = 1;; test++) {
        int n, m;
        Graph* g = (Graph*)malloc(sizeof(Graph));
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) visited[i] = 0;
        cnt = cycle = 0;
        init(g, n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            push(g, u, v);
            push(g, v, u);
        }
        //printlist(g);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                flag = false;
                ++cnt;
                DFS(g, i, -1);
                if (flag) cycle++;
            }
        }
        printf("Case %d: ", test);
        if (cnt - cycle == 0) printf("No trees.\n");
        else if (cnt - cycle == 1) printf("There is one tree.\n");
        else printf("A forest of %d trees.\n", cnt - cycle);
        free(g);
    }
    return 0;
}