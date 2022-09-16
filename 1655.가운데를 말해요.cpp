#include <stdio.h>
#include <stdlib.h>

int min_heap[100001] = { 0, };
int max_heap[100001] = { 0, };
int min_cnt = 0;
int max_cnt = 0;
int heap[101];
void min_push(int x) {
    min_heap[++min_cnt] = x;
    int child = min_cnt;
    int parent = child / 2;

    while (child > 1 && min_heap[child] < min_heap[parent]) {
        int temp = min_heap[child];
        min_heap[child] = min_heap[parent];
        min_heap[parent] = temp;

        child = parent;
        parent = child / 2;
    }
}
int min_pop() {
    if (min_cnt == 0) return 0;
    int r = min_heap[1];
    min_heap[1] = min_heap[min_cnt];
    min_cnt--;
    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= min_cnt) {
        child = min_heap[child] < min_heap[child + 1] ? child : child + 1;
    }
    while (child <= min_cnt && min_heap[child] < min_heap[parent]) {
        int temp = min_heap[child];
        min_heap[child] = min_heap[parent];
        min_heap[parent] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= min_cnt) {
            child = min_heap[child] < min_heap[child + 1] ? child : child + 1;
        }
    }
    return r;
}
void max_push(int x) {
    max_heap[++max_cnt] = x;
    int child = max_cnt;
    int parent = child / 2;

    while (child > 1 && max_heap[child] > max_heap[parent]) {
        int temp = max_heap[child];
        max_heap[child] = max_heap[parent];
        max_heap[parent] = temp;

        child = parent;
        parent = child / 2;
    }
}
int max_pop() {
    if (max_cnt == 0) return 0;
    int r = max_heap[1];
    max_heap[1] = max_heap[max_cnt];
    max_cnt--;
    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= max_cnt) {
        child = max_heap[child] > max_heap[child + 1] ? child : child + 1;
    }
    while (child <= max_cnt && max_heap[child] > max_heap[parent]) {
        int temp = max_heap[child];
        max_heap[child] = max_heap[parent];
        max_heap[parent] = temp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= max_cnt) {
            child = max_heap[child] > max_heap[child + 1] ? child : child + 1;
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
        if (max_cnt == min_cnt) {
            max_push(x);
        }
        else min_push(x);
        if (max_cnt >= 1 && min_cnt >= 1 && max_heap[1] > min_heap[1]) {
            int max_top = max_pop();
            int min_top = min_pop();
            max_push(min_top);
            min_push(max_top);
        }
        printf("%d\n", max_heap[1]);
    }
    return 0;
}