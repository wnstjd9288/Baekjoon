#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long setA[2000001];
long long setB[2000001];
int arr[41];
long long cnt = 0;
int n, k;
int cmp(const void* a, const void* b) {
    return *(long long*)a - *(long long*)b;
}
void mitm(int left, int right, long long set[], long long sum) {
    if (left == right) {
        set[cnt++] = sum;
        return;
    }
    mitm(left + 1, right, set, sum);
    mitm(left + 1, right, set, sum + arr[left]);
}

int lo_bound(long long num, int s, int e) {
    int mid;
    while (e > s) {
        mid = (s + e) / 2;
        if (setB[mid] + num < k) s = mid + 1;
        else e = mid;
    }
    return e;
}
int up_bound(long long num, int s, int e) {
    int mid;
    while (e > s) {
        mid = (s + e) / 2;
        if (setB[mid] + num <= k) s = mid + 1;
        else e = mid;
    }
    return e;
}
int main() {

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mitm(0, n/2, setA, 0);
    int Alen = cnt;
    cnt = 0;
    mitm(n / 2, n, setB, 0);
    int Blen = cnt;
    qsort(setB, Blen, sizeof(long long), cmp);
    cnt = 0;
    if (!k)cnt--;
    for (int i = 0; i < Alen; i++) {
        cnt += up_bound(setA[i], 0, Blen) - lo_bound(setA[i], 0, Blen);
    }
    printf("%lld", cnt);
    return 0;
}