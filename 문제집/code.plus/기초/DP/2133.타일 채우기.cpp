#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int DP[31] = { 0, };
	scanf("%d", &n);
	DP[0] = 1;
	DP[1] = 0;
	DP[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		for (int j = i - 4; j >= 0; j -= 2) {
			DP[i] += DP[j];
		}
		DP[i] = DP[i] * 2 + DP[i - 2] * 3;
	}
	printf("%d", DP[n]);
}