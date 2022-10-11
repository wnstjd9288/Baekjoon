#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int v;
    int w;
}Data;
int min(int a, int b) {
    return a < b ? a : b;
}
int visited[100001];
Data heap[100001];
int cnt = 0;
// Heap_push : heap에 데이터를 추가하는 함수
void Heap_push(Data x) {
    heap[++cnt] = x;
    int child = cnt;
    int parent = child / 2;

    while (child > 1 && heap[child].w < heap[parent].w) {
        Data temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        child = parent;
        parent = child / 2;
    }
}
// pop : heap의 top을 배열에서 지우며 리턴해주는 함수
Data pop() {

    Data r = heap[1];
    heap[1] = heap[cnt];
    cnt--;
    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= cnt) {
        child = heap[child].w < heap[child + 1].w ? child : child + 1;
    }
    while (child <= cnt && heap[child].w < heap[parent].w) {
        Data temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= cnt) {
            child = heap[child].w < heap[child + 1].w ? child : child + 1;
        }
    }
    return r;
}

int main() {
    int n, k, res = 99999999;
    Data start;
    scanf("%d %d", &n, &k);
    start = { n,1 };
    Heap_push(start);
    visited[start.v] = 1;
    while (cnt > 0) {
        Data now = pop();
        if (now.v == k) {
            res = now.w;
            break;
        }
        Data next = now;
        next.v = now.v * 2;
        if (next.v <= 100000) {
            if (!visited[next.v] || visited[next.v] > next.w) {
                Heap_push(next);
                visited[next.v] = next.w;
            }
        }
        next.v = now.v + 1;
        next.w = now.w + 1;
        if (next.v <= 100000) {
            if (!visited[next.v] || visited[next.v] > next.w) {
                Heap_push(next);
                visited[next.v] = next.w;
            }
        }
        next.v = now.v - 1;
        next.w = now.w + 1;
        if (next.v >= 0) {
            if (!visited[next.v] || visited[next.v] > next.w) {
                Heap_push(next);
                visited[next.v] = next.w;
            }
        }
    }
    printf("%d", res - 1);
}