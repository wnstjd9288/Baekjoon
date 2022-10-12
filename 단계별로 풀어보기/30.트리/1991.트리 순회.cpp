#include <stdio.h>
#include <stdlib.h>

char BiTree[10001] = { 0, };
int pos = 0;
void FindRoot(char root, int now) {
    
    if (!BiTree[now]) return;
    if (BiTree[now] == root) pos = now;
    if (!pos) {
        FindRoot(root, now * 2);
        FindRoot(root, now * 2 + 1);
    }
}
void Preorder(int now) {
    if (!BiTree[now]) return;
    printf("%c", BiTree[now]);
    Preorder(now * 2);
    Preorder(now * 2 + 1);
}
void Inorder(int now) {
    if (!BiTree[now]) return;
    Inorder(now * 2);
    printf("%c", BiTree[now]);
    Inorder(now * 2 + 1);
}
void Postorder(int now) {
    if (!BiTree[now]) return;
    Postorder(now * 2);
    Postorder(now * 2 + 1);
    printf("%c", BiTree[now]);
}
int main() {
    int n;
    int cnt = 1;
    scanf("%d", &n);
    BiTree[1] = 'A';
    for (int i = 0; i < n; i++) {
        char root, left, right;
        scanf("%*c%c %c %c", &root, &left, &right);
        pos = 0;
        FindRoot(root, 1);
        if (left != '.') {
            BiTree[pos * 2] = left;
            cnt++;
        }
        if (right != '.') {
            BiTree[pos * 2 + 1] = right;
            cnt++;
        }
    }
    Preorder(1); puts("");
    Inorder(1); puts("");
    Postorder(1); puts("");
    return 0;
}