#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
	int data;
	_Node* next;
}Node;

typedef struct Graph {
	int n;
	Node* adj_list[2001];
}Graph;

void init(Graph* g, int n) {
	g->n = n;
	for (int i = 0; i < n; i++) g->adj_list[i] = NULL;
}

void push(Graph* g, int u, int v) {

	Node* node = (Node*)malloc(sizeof(Node));
	node->data = v;
	node->next = g->adj_list[u];
	g->adj_list[u] = node;

}

void printlist(Graph* g) {
	for (int i = 0; i < g->n; i++) {
		Node* p = g->adj_list[i];
		printf("%d ", i);
		while (p != NULL) {
			printf("-> %d ", p->data);
			p = p->next;
		}
		puts("");
	}
}

int visited[2001] = { 0, };
bool flag = false;

void DFS(Graph* g, int now, int depth) {
	if (flag) return;
	if (depth == 5) {
		flag = true;
		return;
	}
	Node* i;
	visited[now] = 1;
	for (i = g->adj_list[now]; i; i = i->next) {
		if (!visited[i->data]) DFS(g, i->data, depth + 1);
	}
	visited[now] = 0;

}

int main() {
	int n, m;
	Graph* g = (Graph*)malloc(sizeof(Graph));
	scanf("%d %d", &n, &m);
	init(g, n);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		push(g, u, v);
		push(g, v, u);
	}
	//printlist(g);
	for (int i = 0; i < n; i++) {
		if (!flag) {
			for (int j = 0; j < n; j++) visited[j] = 0;
			DFS(g, i, 1);
		}
	}
	if (flag) printf("1");
	else printf("0");
}