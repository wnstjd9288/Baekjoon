#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
}Node;

// Graph : ���� ����Ʈ
typedef struct Graph {
    int n;
    Node* adj_list[100001];
}Graph;

// init : �ʱ�ȭ �Լ�
void init(Graph* g, int n) {
    g->n = n;
    for (int i = 1; i <= n; i++) g->adj_list[i] = NULL;
}

// push : ��������Ʈ ���� �Լ�
void push(Graph* g, int u, int v) {

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = v;
    node->next = g->adj_list[u];
    g->adj_list[u] = node;

}
// sortedMerge : ���ĵ� �迭�� ���� �����ϴ� �Լ�
Node* sortedMerge(Node* a, Node* b) {

    if (a == NULL) {
        return b;
    }
    else if (b == NULL)return a;

    Node* res = NULL;

    if (a->data >= b->data) { // �������� ����
        res = a;
        res->next = sortedMerge(a->next, b);
    }
    else {
        res = b;
        res->next = sortedMerge(a, b->next);
    }
    return res;
}
// Split : �ʱ� �迭�� ������ �ɰ��� �Լ�
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
// mergesort : ���� ���� �Լ�
void mergesort(Node** node) {

    if (*node == NULL || (*node)->next == NULL) return;

    Node* a = NULL;
    Node* b = NULL;

    Split(*node, &a, &b);
    mergesort(&a);
    mergesort(&b);

    *node = sortedMerge(a, b);
}
// printlist : ���� ����Ʈ ��� �Լ�
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

int visited[100001] = { 0, };
int cnt = 0;
// DFS : ���� �켱 Ž�� �Լ�
void DFS(Graph* g, int r) {

    visited[r] = ++cnt;
    Node* i;
    for (i = g->adj_list[r]; i; i = i->next) {
        if (!visited[i->data]) {
            DFS(g, i->data);
        }
    }
}

int main() {
    int n, m, r;
    Graph* g = (Graph*)malloc(sizeof(Graph));
    scanf("%d %d %d", &n, &m, &r);
    init(g, n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push(g, u, v);
        push(g, v, u);
    }
    for (int i = 1; i <= n; i++) {
        mergesort(&g->adj_list[i]);
    }
    DFS(g, r);
    for (int i = 1; i <= n; i++)printf("%d\n", visited[i]);
    return 0;
}