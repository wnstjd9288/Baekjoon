#include<stdio.h>
#include<stdlib.h>

int DP[201][201] = { 0, };

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) DP[1][i] = 1;
	for (int i = 1; i <= k; i++) DP[i][1] = i;

	for (int i = 2; i <= k; i++) {
		for (int j = 2; j <= n; j++) {
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000000;
		}
	}
	printf("%d", DP[k][n]);
}