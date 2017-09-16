#include <iostream>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
node* getNewNode(int x) {
    node* temp = new node();
    temp -> data = x;
    temp -> right = NULL;
    temp -> left = NULL;
    return temp;
}
node* root = getNewNode(1);
void createTree() {
    root->right = getNewNode(3);
    root->right->right = getNewNode(7);
    root->right->left = getNewNode(6);
    root->left = getNewNode(2);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
}
void inOrder(node* t) {
    if (t == NULL) {
        return;
    }
    inOrder(t->left);
    std::cout << t->data << ' ';
    inOrder(t->right);
}
int main(int argc, char const *argv[]) {
    createTree();
    inOrder(root);
    return 0;
}
