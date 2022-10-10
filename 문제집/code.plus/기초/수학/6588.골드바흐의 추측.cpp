#include<stdio.h>
int prime[1000001] = { 0, };
int main() {
	int n;
	int i, j;
	int cnt;
	int top, bottom;
	prime[0] = 1;
	prime[1] = 1;
	for (i = 2; i <= 1000000; i++) {
		if (!prime[i]) {
			for (j = i * 2; j <= 1000000; j += i) {
				prime[j] = 1;
			}
		}
	}
	while(1) {
		scanf("%d", &n);
		if (n == 0) break;
		top = 3;
		bottom = n;
		while (1) {
			if (top > bottom) {
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}
			if (prime[top]) {
				top++;
				continue;
			}
			if (prime[bottom]) {
				bottom--;
				continue;
			}
			if (top + bottom == n) {
				printf("%d = %d + %d\n", n, top, bottom);
				break;
			}
			else if (top + bottom > n) {
				bottom--;
			}
			else {
				top++;
			}
		}
	}

}