#include <stdio.h>
#include <stdlib.h>

int heap[100001] = { 0, };
int cnt = 0;

void push(int x) {
    heap[++cnt] = x;
    int child = cnt;
    int parent = child / 2;

    while (child > 1 && abs(heap[child]) <= abs(heap[parent])) {
        if (abs(heap[child]) == abs(heap[parent]) && heap[child] >= heap[parent]) break;
        int temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        child = parent;
        parent = child / 2;
    }
}
int pop() {
    if (cnt == 0) return 0;
    int r = heap[1];
    heap[1] = heap[cnt];
    cnt--;
    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= cnt) {
        if (abs(heap[child]) == abs(heap[child + 1])) child = heap[child] < heap[child + 1] ? child : child + 1;
        else child = abs(heap[child]) < abs(heap[child + 1]) ? child : child + 1;
    }
    while (child <= cnt && abs(heap[child]) <= abs(heap[parent])) {
        if (abs(heap[child]) == abs(heap[parent]) && heap[child] >= heap[parent]) break;
        int temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= cnt) {
            if (abs(heap[child]) == abs(heap[child + 1])) child = heap[child] < heap[child + 1] ? child : child + 1;
            else child = abs(heap[child]) < abs(heap[child + 1]) ? child : child + 1;
        }
    }
    return r;
}
int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 0)printf("%d\n", pop());
        else {
            push(x);
        }
    }
    return 0;
}