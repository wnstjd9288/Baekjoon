#include<stdio.h>
#include<string.h>
int main() {
	char num1[100001] = { 0, };
	char num2[100001] = { 0, };
	char result[100001] = { 0, };
	int len1;
	int len2;
	int maxlen;
	int cnt = 0;
	scanf("%s %s", num1, num2);
	len1 = strlen(num1);
	len2 = strlen(num2);

	if (len1 >= len2) maxlen = len1;
	else maxlen = len2;

	while (1) {
		if (len1 - cnt == 0 || len2 - cnt == 0) break;
		result[cnt] += num1[len1 - cnt - 1] + num2[len2 - cnt - 1] - 48;
		if (result[cnt] > 57) {
			result[cnt] -= 10;
			result[cnt + 1]++;
		}
		cnt++;
	}
	for (int i = cnt; i < maxlen; i++) {
		if (maxlen == len1)
			result[i] += num1[maxlen - i - 1];
		else
			result[i] += num2[maxlen - i - 1];
		if (result[i] > 57) {
			result[i] -= 10;
			result[i + 1]++;
		}
	}
	for (int i = strlen(result) - 1; i >= 0; i--) {
		if (result[i] < 47)result[i] += 48;
		printf("%c", result[i]);
	}
}