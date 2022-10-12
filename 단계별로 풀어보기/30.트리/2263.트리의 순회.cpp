#include <stdio.h>
#include <stdlib.h>

int postorder[100001];
int inorder[100001];
int index[100001];

void preorder(int instart, int inend, int poststart, int postend) {
    if (instart > inend || poststart > postend) return;
    int rootindex = index[postorder[postend]];
    int leftsize = rootindex - instart;
    
    printf("%d ", inorder[rootindex]);

    preorder(instart, rootindex - 1, poststart, poststart + leftsize - 1);
    preorder(rootindex + 1, inend, poststart + leftsize, postend - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &inorder[i]);
        index[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &postorder[i]);
    }
    preorder(1, n, 1, n);
    return 0;
}