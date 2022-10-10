#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int DP[100001][2] = {0,};
int arr[100001] = { 0, };
int m = -1e9;
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	DP[1][0] = arr[1];
	for (int i = 2; i <= n; i++) {
		DP[i][0] = max(arr[i], arr[i] + DP[i - 1][0]);
	}
	DP[1][1] = DP[1][0];
	DP[2][1] = DP[2][0];
	for (int i = 3; i <= n; i++) {
		DP[i][1] = max(DP[i - 2][0] + arr[i], DP[i - 1][0] + arr[i]);
		DP[i][1] = max(DP[i][1], DP[i - 1][1] + arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		m = max(m, DP[i][0]);
		m = max(m, DP[i][1]);
	}
	printf("%d", m);
}