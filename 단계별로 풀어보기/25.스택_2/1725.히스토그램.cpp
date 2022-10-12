#include <stdio.h>

int stack[100011];
int m(long long int a, long long int b) {
    return a > b ? a : b;
}
int main() {

    int n;
    int box[100011] = { 0, };
    int top = 0;
    int max = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &box[i]);
    }
    for (int i = 1; i <= n + 1; i++) {
        while (top != 0 && box[stack[top]] > box[i]) {

            int h = box[stack[top]];
            top--;
            int w = i - stack[top] - 1;
            max = m(max, h * w);
        }
        stack[++top] = i;
    }
    printf("%d", max);
    return 0;
}