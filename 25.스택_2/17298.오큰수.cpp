#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int index;
}grid;

int nge[1000001];
grid A[1000001];
grid stack[1000001];
int top = -1;
void push(grid n) {
    stack[++top] = n;
}
grid pop() {
    return stack[top--];
}
int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i].num);
        A[i].index = i;
        nge[i] = -1;
        if (top == -1) push(A[i]);
        else {
            if (stack[top].num >= A[i].num) push(A[i]);
            else {
                while (top >= 0) {
                    if (stack[top].num >= A[i].num) break;
                    nge[stack[top].index] = A[i].num;
                    pop();
                }
                push(A[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", nge[i]);
    }
    return 0;
}