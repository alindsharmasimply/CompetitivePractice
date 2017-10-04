#include <iostream>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
    int height;
};
int Maximum(int a, int b) {
    return (a > b)? a : b;
}
int Height(node* t)
{
    if (t == NULL) {
        return -1;
    }
    else
        return t->height;
}
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    temp->height = 0;
    return temp;
}
node* rotateRight(node* X)
{
    node* Y = X->left;
    X->left = Y->right;
    Y->right = X;
    X->height = Maximum(Height(X->left), Height(X->right)) + 1;
    Y->height = Maximum(Height(Y->left), X->height);
    return Y;
}
node* rotateLeft(node* X)
{
    node* Y = X->right;
    X->right = Y->left;
    Y->left = X;
    X->height = Maximum(Height(X->left), Height(X->right)) + 1;
    Y->height = Maximum(Height(Y->right), X->height);
    return Y;
}
node* insert(node* temp, int x)
{
    if (temp == NULL) {
        return getNewNode(x);
    }
    if (temp->data > x) {
        temp->left = insert(temp->left, x);
    }
    if (temp->data < x) {
        temp->right = insert(temp->right, x);
    }
    else
        return temp;

        temp->height = Maximum(Height(temp->left), Height(temp->right)) + 1;

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
int rangeAVL(node* temp, int a, int b)
{
    if (temp == NULL) {
        return 0;
    }
    else if (temp->data < a) {
        return rangeAVL(temp->right, a, b);
    }
    else if (temp->data > b) {
        return rangeAVL(temp->left, a, b);
    }
    else if (temp->data >= a && temp->data <= b) {
        return rangeAVL(temp->left, a, b) + rangeAVL(temp->right, a, b) + 1;
    }
}
int main(int argc, char const *argv[]) {
    node* root = NULL;
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 9);
    cout << "Number of nodes are = "<< rangeAVL(root, 5, 8);
    return 0;
}
