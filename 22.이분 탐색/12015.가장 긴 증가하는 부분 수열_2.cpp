#include <stdio.h>
#include <stdlib.h>

int n;
int arr[1000001];
int LTS[1000001] = { 0, };
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int lo_bound(int high, int low, int k) {

    int mid;

    while (high > low) {
        mid = (high + low) / 2;
        if (LTS[mid] < k) {
            low = mid + 1;
        }
        else high = mid;
    }
    return high;
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int cnt = -1;
    LTS[++cnt] = arr[0];
    for (int i = 1; i < n; i++) {
        if (LTS[cnt] < arr[i])LTS[++cnt] = arr[i];
        else {
            int index = lo_bound(cnt + 1, 0, arr[i]);
            LTS[index] = arr[i];
        }
    }
    printf("%d", cnt + 1);
    return 0;
}