#include<stdio.h>
int prime[10001] = { 0, };
int main() {
	int n;
	int i, j;
	int cnt;
	int top, bottom;
	prime[0] = 1;
	prime[1] = 1;
	for (i = 2; i <= 10000; i++) {
		if (!prime[i]) {
			for (j = i * 2; j <= 10000; j += i) {
				prime[j] = 1;
			}
		}
	}
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		scanf("%d", &n);
		top = bottom = n / 2;
		while (1) {
			if (prime[top]) {
				top++;
				continue;
			}
			if (prime[bottom]) {
				bottom--;
				continue;
			}
			if (top + bottom == n) {
				printf("%d %d\n", bottom, top);
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