#include<stdio.h>
#include<stdlib.h>

int map[5][5] = { 0, };
int check[5][5] = { 0, };
int sum[5][5] = { 0, };
int n, m;
int max = -1;
int cnt = 0;

void piece(int index) {

	if (index == n * (m + 1) + 2) {
		int res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) sum[i][j] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sum[i][j] += map[i][j];
				if (check[i][j] && !check[i + 1][j]) res += sum[i][j];
				else if (check[i][j] && check[i + 1][j]) sum[i + 1][j] += sum[i][j] * 10;
				else if (!check[i][j] && check[i][j + 1] || !check[i][j] && j == m) res += sum[i][j];
				else if (!check[i][j] && !check[i][j + 1]) sum[i][j + 1] = sum[i][j] * 10;
			}
		}
		if (res > max) max = res;
		return;
	}
	for (int i = index; i <= n * (m + 1) + 1; i++) {
		check[(i - 1) / m][(i - 1) % m + 1] = 1;
		piece(i + 1);
		check[(i - 1) / m][(i - 1) % m + 1] = 0;
		if (i == n * (m + 1) + 1) piece(i + 1);
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	piece(m + 1);
	printf("%d", max);
}