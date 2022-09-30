#include <stdio.h>
#include <stdlib.h>

int prime[4000001] = { 0, };
int a[400001] = { 0, };
long long sum[400001]={0,};
int main() {
    int n;
    int cnt = 0;
    scanf("%d", &n);
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            for (int j = i * 2; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            a[++cnt] = i;
            sum[cnt] = sum[cnt - 1] + a[cnt];
        }
    }
    int s = 0, e = 1;
    int count = 0;
    while (s < e) {
        long long now = sum[e] - sum[s];
        if (now == n) {
            count++;
        }
        if (now > n) s++;
        else e++;
    }
    printf("%d", count);
    return 0;
}