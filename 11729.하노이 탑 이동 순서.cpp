#include <stdio.h>
void hanoi(int n, int start, int to, int temp)
{
    if (n == 1)
        printf("%d %d\n", start, to);
    else
    {
        hanoi(n - 1, start, temp, to);
        printf("%d %d\n", start, to);
        hanoi(n - 1, temp, to, start);
    }
}
int main() {

    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n, 1, 3, 2);
    return 0;
}