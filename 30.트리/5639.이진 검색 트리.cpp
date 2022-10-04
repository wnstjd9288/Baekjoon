#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;
}Node;

void postorder(Node* root) {

    if (root->left != NULL) postorder(root->left);
    if (root->right != NULL) postorder(root->right);
    printf("%d\n", root->data);

}

int main() {
    int n;
    int cnt = 0;
    scanf("%d", &n);
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = n; root->left = NULL; root->right = NULL;
    while (scanf("%d", &n) == 1) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = n; node->left = NULL; node->right = NULL;
        
        Node* temp = root;
        while (1) {
            if (temp->data > node->data) {
                if (temp->left == NULL) {
                    temp->left = node;
                    break;
                }
                else temp = temp->left;
            }
            else {
                if (temp->right == NULL) {
                    temp->right = node;
                    break;
                }
                else temp = temp->right;
            }
        }
    }
    postorder(root);
    return 0;
}