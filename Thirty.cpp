#include <iostream>
#include <queue>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
queue<node*> Q;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
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
void levelOrder() {
    node* temp;
    if (temp == NULL) {
        return;
    }
    Q.push(root);
    while ( !Q.empty() ) {
        temp = Q.front();
        Q.pop();
        std::cout << temp->data << ' ';
        if (temp->left != NULL) {
            Q.push(temp->left);
        }
        if (temp->right != NULL) {
            Q.push(temp->right);
        }
    }
}
int main(int argc, char const *argv[]) {
    createTree();
    levelOrder();
    return 0;
}
