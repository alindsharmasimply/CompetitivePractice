#include <iostream>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
node* getNewNode(int x) {
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
node* root = getNewNode(10);
void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}
void deletepostOrder(node* t) {
    if (t == NULL) {
        return;
    }
    deletepostOrder(t->left);
    deletepostOrder(t->right);
    delete t;
}
int main(int argc, char const *argv[]) {
    create();
    deletepostOrder(root);
    std::cout << root->data << '\n';
    return 0;
}
