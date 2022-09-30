#include <stdio.h>
#include <stdlib.h>
long long setA[100001];
long long setB[100001];
int weight[31] = { 0, };
int cnt = 0, c;
int cmp(const void* a, const void* b) {
    return *(long long*)a - *(long long*)b;
}
void mitm(int left, int right, long long set[], long long sum) {

    if (left == right) {
        if (sum <= c) set[cnt++] = sum;
        return;
    }
    mitm(left + 1, right, set, sum);
    mitm(left + 1, right, set, sum + weight[left]);

}
long long up_bound(long long k, long long s, long long e,long long arr[]) {

    long long mid;
    while (e - s > 0) {
        mid = (s + e) / 2;
        if (arr[mid] + k <= c) s = mid + 1;
        else e = mid;
    }
    return e;

}
int main() {
    int n;
    long long ans = 0;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
    
    mitm(0, n / 2, setA, 0);
    int Alen = cnt;
    cnt = 0;
    mitm(n / 2, n, setB, 0);
    int Blen = cnt;
    qsort(setB, Blen, sizeof(long long), cmp);

    for (int i = 0; i < Alen; i++) ans += up_bound(setA[i], 0, Blen, setB);
    
    printf("%d", ans);
    return 0;
}