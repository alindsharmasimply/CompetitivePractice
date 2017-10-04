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
    node* temp = new node()
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
    X->height = Maximum(Height(X->left), Height(Y->right)) + 1;
    Y->height = Maximum(Height(Y->left), X->height);
    return Y;
}
node* rotateLeft(node* X)
{
    node* Y = X->right;
    X->left = Y->right;
    Y->right = X;
    X->height = Maximum(Height(X->left), Height(Y->right)) + 1;
    Y->height = Maximum(Height(Y->right), X->height);
    return Y;
}
int main(int argc, char const *argv[]) {
    node* root = NULL;
    root = insert();
    root = insert();
    root = insert();
    root = insert();
    root = insert();
    root = insert();
    root = insert();
    root = insert();
    cout << "Number of nodes are = "<< rangeAVL(root);
    return 0;
}
