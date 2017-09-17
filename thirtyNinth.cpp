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
int level = 1;
node* root = getNewNode(10);
void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}
void heightlevelOrder() {

    Q.push(root);
    Q.push(NULL);
    while (!Q.empty()) {
        root = Q.front();
        Q.pop();
        if (root == NULL) {
            if (!Q.empty()) {
            Q.push(NULL);
        }
        level++;
    }

        else{
            if (root->left != NULL) {
                Q.push(root->left);
            }
            if (root->right != NULL) {
                Q.push(root->right);
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    create();
    heightlevelOrder();
    std::cout << "The height of the tree is " << '\n';
    std::cout << level << '\n';
    return 0;
}
