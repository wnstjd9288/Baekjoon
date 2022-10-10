#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
}Node;

// Graph : 인접 리스트
typedef struct Graph {
    int n;
    Node* adj_list[20001];
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

int visited[20001] = { 0, };

// BFS : 너비 우선 탐색 함수
bool BFS(Graph* g, int r) {
    int que[20001];
    int h = -1, t = -1;
    visited[r] = 1;
    que[++t] = r;
    while (h != t) {
        int now = que[++h];
        Node* i;
        for (i = g->adj_list[now]; i; i = i->next) {
            if (!visited[i->data]) {
                que[++t] = i->data;
                visited[i->data] = visited[now] * -1;
            }
            else if (visited[now] == visited[i->data]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++) {
        int n, m;
        bool flag = true;
        Graph* g = (Graph*)malloc(sizeof(Graph));
        scanf("%d %d", &n, &m);
        init(g, n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            push(g, u, v);
            push(g, v, u);
        }
        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                if (BFS(g, i) == false)
                    flag = false;
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}