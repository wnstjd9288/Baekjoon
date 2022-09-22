#include <stdio.h>
#include <stdlib.h>

int n, k;
int arr[10001];

long long line(long long length) {
    int sum = 0;
    for (int i = 0; i < n; i++)sum += arr[i] / length;
    return sum;
}

int main() {

    int max = -1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        max = max > arr[i] ? max : arr[i];
    }
    long long high = max;
    long long low = 1;
    while (high > low) {
        long long mid = (high + low) / 2;
        if (line(mid) >= k && line(mid + 1) < k) break;
        if (line(mid) >= k)low = mid + 1;
        else high = mid - 1;
    }
    printf("%lld", (high + low) / 2);
    return 0;
}