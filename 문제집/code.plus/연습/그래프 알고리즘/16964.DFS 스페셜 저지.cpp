#include <stdio.h>
#include <stdlib.h>
typedef struct _Node {
    int data;
    struct _Node* next;
}Node;

typedef struct Graph {
    int n;
    Node* adj_list[100001];
}Graph;

int order[100001] = { 0, };

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

Node* sortedMerge(Node* a, Node* b) {

    if (a == NULL) {
        return b;
    }
    else if (b == NULL)return a;

    Node* res = NULL;

    if (order[a->data] <= order[b->data]) {
        res = a;
        res->next = sortedMerge(a->next, b);
    }
    else {
        res = b;
        res->next = sortedMerge(a, b->next);
    }
    return res;
}
void Split(Node* node, Node** front, Node** back) {

    Node* slow = node;
    Node* fast = node->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = node;
    *back = slow->next;
    slow->next = NULL;
}
void mergesort(Node** node) {

    if (*node == NULL || (*node)->next == NULL) return;

    Node* a = NULL;
    Node* b = NULL;

    Split(*node, &a, &b);
    mergesort(&a);
    mergesort(&b);

    *node = sortedMerge(a, b);
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
int que[10000001];
int list[100001];
int visited[100001] = { 0, };
int cnt = 0;
bool flag = true;
void DFS(Graph* g, int now) {
    visited[now] = 1;
    if (now != list[++cnt]) {
        flag = false;
        return;
    }
    Node* i;
    for (i = g->adj_list[now]; i; i = i->next) {
        if (!visited[i->data]) DFS(g, i->data);
        if (!flag) return;
    }
}

int main() {
    int n;
    Graph* g = (Graph*)malloc(sizeof(Graph));

    scanf("%d", &n);
    init(g, n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push(g, u, v);
        push(g, v, u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &list[i]);
        order[list[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        mergesort(&g->adj_list[i]);
    }
    //printlist(g);
    DFS(g, 1);
    if (flag) printf("1");
    else printf("0");
    return 0;
}