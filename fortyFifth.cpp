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

void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->right->left = getNewNode(65);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}

void mirror(node* t) {
    node* temp;
    if (t != NULL) {
        mirror(t->left);
        mirror(t->right);
        temp = t->left;
        t->left = t->right;
        t->right = temp;
    }
}

void display(node* t) {
    node* temp;
    Q.push(t);
    while (!Q.empty()) {
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
    create();
    display(root);
    mirror(root);
    std::cout << '\n';
    display(root);
    return 0;
}
