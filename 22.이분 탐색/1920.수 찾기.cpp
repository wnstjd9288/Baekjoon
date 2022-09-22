#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x > y) return 1;
    else if (x == y)return 0;
    else return -1;
}
int main() {
    int n, m;
    int s[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", &s[i]);
    qsort(s, n, sizeof(int), cmp);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int b;
        int h = 0, t = n - 1;
        int mid;
        bool flag = false;
        scanf("%d", &b);
        while (1) {
            if (h > t)break;
            mid = (h + t) / 2;
            if (s[mid] == b) {
                flag = true;
                break;
            }
            else if (s[mid] > b) {
                t = mid - 1;
            }
            else h = mid + 1;

        }
        if (flag)printf("1\n");
        else printf("0\n");
    }


    return 0;
}