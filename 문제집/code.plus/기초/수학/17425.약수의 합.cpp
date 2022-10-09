#include <stdio.h>
#include <stdlib.h>

long long f[1000001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= 1000000; i++) {
		f[i] += f[i - 1];
		for (int j = i; j <= 1000000; j += i) {
			f[j] += i;
		}
	}
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		printf("%lld\n", f[a]+a);
	}
    return 0;
}