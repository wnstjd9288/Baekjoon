#include <stdio.h>
#include <stdlib.h>
int n;
int arr[11];
int used[10] = { 0, };
long long max = -1;
long long min = 1e10;
void inequal(int now,int prev,long long sum) {
    if (now == n) {
        if (max < sum)max = sum;
        if (min > sum)min = sum;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (arr[now]) {
            if (i > prev && !used[i]) {
                used[i] = 1;
                inequal(now + 1, i, sum * 10 + i);
                used[i] = 0;
            }
        }
        else {
            if (i < prev && !used[i]) {
                used[i] = 1;
                inequal(now + 1, i, sum * 10 + i);
                used[i] = 0;
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char a;
        scanf("%*c%c", &a);
        if (a == '<')arr[i] = 1;
        else arr[i] = 0;
    }

    for (int i = 0; i <= 9; i++) {
        used[i] = 1;
        inequal(0, i, i);
        used[i] = 0;
    }
    if(max/min>=10) printf("%lld\n0%lld", max, min);
    else printf("%lld\n%lld", max, min);
    return 0;
}