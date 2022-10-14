#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[1001] = { 0, };
int A[1000001];
int B[1000001];
long long cnt = 0;
int t;
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int lo_bound(long long num, int s, int e) {
    int mid;
    while (e > s) {
        mid = (s + e) / 2;
        if (B[mid] + num < t) s = mid + 1;
        else e = mid;
    }
    return e;
}
int up_bound(long long num, int s, int e) {
    int mid;
    while (e > s) {
        mid = (s + e) / 2;
        if (B[mid] + num <= t) s = mid + 1;
        else e = mid;
    }
    return e;
}
int main() {

    int n, m;
    scanf("%d", &t);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        arr[i] = arr[i - 1] + a;
        A[cnt++] = arr[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            A[cnt++] = arr[j] - arr[i];
        }
    }
    int Alen = cnt;
    cnt = 0;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int a;
        scanf("%d", &a);
        arr[i] = arr[i - 1] + a;
        B[cnt++] = arr[i];
    }
    for (int i = 1; i < m; i++) {
        for (int j = i + 1; j <= m; j++) {
            B[cnt++] = arr[j] - arr[i];
        }
    }
    int Blen = cnt;
    qsort(B, Blen, sizeof(int), cmp);
    cnt = 0;
    for (int i = 0; i < Alen; i++) {
        cnt += up_bound(A[i], 0, Blen) - lo_bound(A[i], 0, Blen);
    }
    printf("%lld", cnt);
    return 0;
}