#include <iostream>
using namespace std;
struct node {
    int data;
    int RTag;
    int LTag;
    node* right;
    node* left;
};
node* getNewNode(int x) {
    node* temp = new node();
    temp->data = x;
    temp->RTag = 1;
    temp->LTag = 1;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
node* realRoot = getNewNode(0);
node* root = getNewNode(10);
void create() {
    realRoot->left = root;
    realRoot->right = realRoot;
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
    root->left->left->RTag = root->left->left->LTag = 0;
    root->right->right->RTag = root->right->right->LTag = 0;
    root->right->left->RTag = root->right->left->LTag = 0;
    root->left->right->RTag = root->left->right->LTag = 0;
}

node* inorderSuccessor(node* P) {
    node* position;
    if (P->RTag == 0) {
        return P->right;
    }
    else
    {
        position = P->right;
        while (position->LTag == 1) {
            position = position->left;
        }
        return position;
    }
}
void inorderTraversal(node* roo) {
    node* P = roo;
    while (1) {

        P = inorderSuccessor(P);
        if (P == roo) {
            return;
        }
        std::cout << P->data << '\n';
    }
}

int main(int argc, char const *argv[]) {
    create();
    inorderTraversal(realRoot);
    return 0;
}
