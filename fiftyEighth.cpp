#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
    int height;
};
queue<node*> Q;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    temp->height = 0;
    return temp;
}
int Height(node* t)
{
    if (t == NULL) {
        return -1;
    }
    else
    return t->height;
}
int Maximum(int a, int b)
{
    return (a>b)? a: b;
}
node* rotateRight(node* X)
{
    node* Y = X->left;
    X->left = Y->right;
    Y->right = X;
    X->height = Maximum(Height(X->right), Height(X->left)) + 1;
    Y->height = Maximum(Height(Y->left), X->height);
    return Y;
}
node* rotateLeft(node* X)
{
    node* Y = X->right;
    X->right = Y->left;
    Y->left = X;
    X->height = Maximum(Height(X->right), Height(Y->left));
    Y->height = Maximum(Height(Y->right), X->height);
}
node* insert(node* temp, int x)
{
    if (temp == NULL) {
        return getNewNode(x);
    }
        if (temp-> data > x) {
            temp->left = insert(temp->left, x);
        }
        else if (temp->data < x) {
            temp->right = insert(temp->right, x);
        }
        else
            return temp;

    temp->height = Maximum(Height(temp->right), Height(temp->left)) + 1;

    int bal = Height(temp->left) - Height(temp->right);

    if (bal > 1 && temp->left->data > x) {
        return rotateRight(temp);
    }
    if (bal < -1 && temp->right->data < x) {
        return rotateLeft(temp);
    }
    if (bal > 1 && temp->left->data < x) {
        temp->left = rotateLeft(temp->left);
        return rotateRight(temp);
    }
    if (bal < -1 && temp->right->data > x) {
        temp->right = rotateRight(temp->right);
        return rotateLeft(temp);
    }
    return temp;
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
int isAVL(node* t)
{
    int left, right;
    if (t == NULL) {
        return 0;
    }
    left = isAVL(t->left);
    if (left == -1) {
        return left;
    }
    right = isAVL(t->right);
    if (right == -1) {
        return right;
    }
    if (abs(left - right) > 1) {
        return -1;
    }
    return Maximum(left, right) + 1;
}
int main(int argc, char const *argv[]) {
    node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 45);
    display(root);
    std::cout << '\n';
    int check = isAVL(root);
    if (check == -1) {
        std::cout << "The tree is not AVL." << '\n';
    }
    else
    std::cout << "The tree is AVL." << '\n';
    return 0;
}
