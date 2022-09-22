#include <stdio.h>
#include <stdlib.h>

int n, k;
int arr[1000001];

long long cut(long long length) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] - length > 0) sum += arr[i] - length;
    return sum;
}

int main() {

    long long max = -1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        max = max > arr[i] ? max : arr[i];
    }
    long long high = max;
    long long low = 0;
    max = -1;
    while (high >= low) {
        long long mid = (high + low) / 2;
        if (cut(mid) >= k) {
            low = mid + 1;
            if (max < mid)max = mid;
        }
        else high = mid - 1;
    }
    printf("%lld", max);
    return 0;
}