#include <stdio.h>
#include <stdlib.h>

typedef struct grid {
    int data;
    long long stric;
}grid;

int arr[500001];
grid stack[500001];
int top = -1;
long long res = 0;
int main() {

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        while (top >= 0 && arr[stack[top].data] < arr[i]) {
            res += stack[top--].stric;
        }
        if (top >= 0) {
            if (arr[stack[top].data] == arr[i]) {
                res += stack[top].stric;
                cnt = stack[top--].stric + 1;
                if (top >= 0) res++;
            }
            else res++;
        }
        stack[++top] = { i,cnt };
    }
    printf("%lld", res);
    return 0;
}