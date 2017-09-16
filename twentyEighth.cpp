#include <iostream>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
};
node* getNewNode(int x) {
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
node* root = getNewNode(1);
void createTree() {
    root->left = getNewNode(2);
    root->right = getNewNode(3);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right->left = getNewNode(6);
    root->right->right = getNewNode(7);
}
void preOrder(node* t) {
    if (t == NULL) {
        return;
    }
    std::cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}
int main(int argc, char const *argv[]) {
    createTree();
    preOrder(root);
    return 0;
}
