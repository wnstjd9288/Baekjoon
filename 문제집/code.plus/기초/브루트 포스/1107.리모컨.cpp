#include<stdio.h>
#include<stdlib.h>

int n;
int arr[11] = { 0, };
int min;

void remote(int ch, int lev) {


	if (abs(ch - n) + lev < min)min = abs(ch - n) + lev;
	if (ch >= n * 2) return;
	for (int i = 0; i <= 9; i++) {
		if (i == 0 && ch == 0) continue;
		if (!arr[i]) remote(ch * 10 + i, lev + 1);
	}
}

int main() {

	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		arr[a] = 1;
	}
	min = abs(n - 100);
	for (int i = 0; i <= 9; i++) {
		if (!arr[i]) remote(i, 1);
	}
	printf("%d", min);
}