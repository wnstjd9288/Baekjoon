#include <stdio.h>
#include <stdlib.h>

int n, c;
int arr[1000001];

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {

    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    int high = arr[n - 1];
    int low = 0;
    int max = 0;
    while (high >= low) {
        int mid = (high + low) / 2;
        int cnt = 1;
        int prev = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] - prev >= mid) {
                cnt++;
                prev = arr[i];
            }
        }
        if (cnt >= c) {
            if (max < mid)max = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    printf("%d", max);
    return 0;
}