#include <stdio.h>
#include <stdlib.h>

int arr[1000001];
int F[1000001];
int stack[1000001];
int result[1000001] = { 0, };
int top = -1;
int main() {

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        F[arr[i]]++;
    }
    stack[++top] = 1;
    for (int i = 2; i <= n; i++) {
        while (F[arr[stack[top]]] < F[arr[i]] && top >= 0) {
            result[stack[top]] = arr[i];
            top--;
        }
        stack[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (!result[i]) printf("-1 ");
        else printf("%d ", result[i]);
    }
    return 0;
}