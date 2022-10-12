#include <stdio.h>
#include <stdlib.h>

int n, k;
int arr[1000001];

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {

    scanf("%d %d", &n, &k);
    int high = k;
    int low = 1;
    int res = 0;
    while (high >= low) {
        int mid = (high + low) / 2;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }
        if (cnt >= k) {
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    printf("%d", res);
    return 0;
}