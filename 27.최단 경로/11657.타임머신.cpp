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

long long weight[2001];
bool Ford(Graph* g, int r,int n) {

    weight[r] = 0;
    for (int j = 1; j <= n; j++) {
        for (int node = 1; node <= n; node++) {
            Node* i;
            for (i = g->adj_list[node]; i; i = i->next) {
                int now = node;
                int next = i->data.v;
                int cost = i->data.w;

                if (weight[now] == 1e8) continue;
                if (weight[next] > weight[now] + cost) {

                    weight[next] = weight[now] + cost;
                    if (j == n) return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    Graph* g = (Graph*)malloc(sizeof(Graph));
    scanf("%d %d", &n, &m);
    init(g, n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        push(g, u, v, w);
    }
    for (int i = 1; i <= n; i++) {
        weight[i] = 1e8;
    }
    //printlist(g);
    bool flag = Ford(g, 1, n);
    if (!flag) printf("-1");
    else {
        for (int i = 2; i <= n; i++) {
            if (weight[i] == 1e8) printf("-1\n");
            else printf("%lld\n", weight[i]);
        }
    }

    return 0;
}