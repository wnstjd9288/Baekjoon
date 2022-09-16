#include<stdio.h>
int prime[1000001] = { 0, };
int main() {
	int a, b;
	int i, j;
	int cnt = 0;
	scanf("%d%d", &a, &b);
	prime[1] = 1;
	for (i = 2; i <= 1000000; i++) {
		if (!prime[i]) {
			for (j = i * 2; j <= 1000000; j += i) {
				prime[j] = 1;
			}
		}
	}
	for (i = a; i <= b; i++) {
		if (!prime[i])
			printf("%d\n", i);
	}
}