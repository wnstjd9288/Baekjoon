#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int arr[1001] = { 0, };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		for (int j = 1; j <= i - 1; j++) {
			arr[i] = max(arr[i - j] + arr[j], arr[i]);
		}
	}
	printf("%d", arr[n]);
}