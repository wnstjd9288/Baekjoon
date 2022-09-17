#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x > y) return 1;
    else if (x == y)return 0;
    else return -1;
}

int arr[500001];

int lo_bound(int k, int s, int e) {

    int mid;
    while (e - s > 0) {
        mid = (s + e) / 2;
        if (arr[mid] < k) s = mid + 1;
        else e = mid;
    }
    return e;

}
int up_bound(int k, int s, int e) {

    int mid;
    while (e - s > 0) {
        mid = (s + e) / 2;
        if (arr[mid] <= k) s = mid + 1;
        else e = mid;
    }
    return e;

}
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    scanf("%d", &m);
    int a;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        printf("%d ", up_bound(a, 0, n) - lo_bound(a, 0, n));
    }
    return 0;
}