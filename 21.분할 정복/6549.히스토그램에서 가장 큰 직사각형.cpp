#include <stdio.h>

int n;
int box[100001] = { 0, };

long long int max(long long int a, long long int b) {
    return a > b ? a : b;
}

long long int histogram(int s, int e) {

    if (s == e)return 0;
    if (s == e - 1) return box[s];

    int mid = (s + e) / 2;
    long long int res = max(histogram(s, mid), histogram(mid, e));

    int width = 1;
    long long int height = box[mid];
    int left = mid;
    int right = mid;

    while (e - s > right - left + 1) {
        long long int p = -1, q = -1;
        if (left - 1 >= s) {
            p = height < box[left - 1] ? height : box[left - 1];
        }
        if (right + 1 < e) {
            q = height < box[right + 1] ? height : box[right + 1];
        }

        if (p >= q) {
            height = p;
            left--;
        }
        else {
            height = q;
            right++;
        }
        width++;
        res = max(res, width * height);
    }
    return res;
}

int main() {

    while (1) {
        scanf("%d", &n);
        if (n == 0)break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &box[i]);
        }

        printf("%lld\n", histogram(0, n));
    }
    return 0;
}