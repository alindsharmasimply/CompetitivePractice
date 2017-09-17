#include <iostream>
#include <queue>
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
queue<node*> Q;
node* root = getNewNode(10);
int size = 0;
void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}
void sizelevelOrder() {
    node* temp;
    Q.push(root);
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        size++;
        if (temp -> left != NULL) {
            Q.push(temp->left);
        }
        if (temp -> right != NULL) {
            Q.push(temp->right);
        }
    }
}
int main(int argc, char const *argv[]) {
    create();
    sizelevelOrder();
    std::cout << "The size of the tree is " << '\n';
    std::cout << size << '\n';
    return 0;
}
