#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
typedef struct grid {
    int data;
    int rank = 0;
    int cnt = 1;
}Set;

using namespace std;
Set set[200001];
char ID[200001][21];
map<string, int> m;

int find(int x) {
    if (set[x].data == x) return x;
    else return set[x].data = find(set[x].data);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (set[x].rank < set[y].rank) {
        set[x].data = y; 
        set[y].cnt += set[x].cnt; 
        set[x].cnt = 1; 
    }
    else {
        set[y].data = x;

        if (set[x].rank == set[y].rank) set[x].rank++;
        set[x].cnt += set[y].cnt;
        set[y].cnt = 1;
    }
}

int main() {
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++) {
        int n;
        int cnt = 0;
        map<string, int> ::iterator it;

        scanf("%d", &n);
        for (int i = 1; i <= n * 2; i++) { 
            set[i].data = i; 
            set[i].cnt = 1;
            set[i].rank = 0;
        }

        for (int i = 1; i <= n; i++) {
            int x, y;
            char s1[21], s2[21];
            scanf("%s %s", s1, s2);
            it = m.find(s1);
            if (it == m.end()) {
                m[s1] = ++cnt;
                x = cnt;
            }
            else {
                x = it->second; 
            }

            it = m.find(s2);
            if (it == m.end()) {
                m[s2] = ++cnt;
                y = cnt;
            }
            else {
                y = it->second;
            }

            union_set(x, y);
            printf("%d\n", set[find(x)].cnt);
        }
    }
    

    return 0;
}