#include <stdio.h>
#include <stdlib.h>

int n;
int arr[1000001];
int LTS[1000001] = { 0, };
int res[1000001] = { 0, };
int lo_bound(int high, int low, int k) {

    int mid;

    while (high > low) {
        mid = (high + low) / 2;
        if (LTS[mid] < k) {
            low = mid + 1;
        }
        else high = mid;
    }
    return high;
}

void print_res(int max,int now) {

    for (int i = now; i >= 0; i--) {
        if (max == res[i]) {
            print_res(max - 1, i);
            printf("%d ", arr[i]);
            return;
        }
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int cnt = -1;
    LTS[++cnt] = arr[0];

    for (int i = 1; i < n; i++) {
        if (LTS[cnt] < arr[i]) {
            LTS[++cnt] = arr[i];  
            res[i] = cnt;
        }
        else {
            int index = lo_bound(cnt + 1, 0, arr[i]);
            LTS[index] = arr[i];
            res[i] = index;
        }
    }
    printf("%d\n", cnt + 1);
    int max = -1;
    for (int i = 0; i < n; i++) {
        max = max > res[i] ? max : res[i];
    }
    print_res(max, n - 1);
    return 0;
}