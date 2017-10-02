#include <iostream>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
    int height;
};
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->height = 1;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
int Height(node* t)
{
    if (t == NULL) {
        return 0;
    }
    else{
        return t->height;
    }
}
int maxi(int a, int b)
{
    return (a > b)? a : b;
}
int getBalance(node* t)
{
    if (t == NULL) {
        return 0;
    }
    else
        return Height(t->left) - Height(t->right);
}
node* singleRotateLeft(node* x) {
    node* y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = maxi(Height(x->left), Height(x->right)) + 1;
    y->height = maxi(Height(y->left), x->height) + 1;
    return y;
}
node* singleRotateRight(node* x)
{
    node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = maxi(Height(x->left), Height(x->right)) + 1;
    y->height = maxi(Height(y->right), y->height) + 1;
    return y;
}
node* insert(node* mark, int x) {
    if (mark == NULL) {
        return getNewNode(x);
    }
        if (x < mark->data) {
            mark->left = insert(mark->left, x);
        }
        else if (x > mark->data) {
            mark->right = insert(mark->right, x);
        }
        else
            return mark;

    mark->height = maxi(Height(mark->right), Height(mark->left)) + 1;

    int bal = getBalance(mark);

    if (bal > 1 && x < mark->left->data) {
        return singleRotateLeft(mark);
    }
    if (bal < -1 && x > mark->right->data) {
        return singleRotateRight(mark);
    }
    if (bal > 1 && x > mark->left->data) {
        mark->left = singleRotateRight(mark->left);
        return singleRotateLeft(mark);
    }
    if (bal < -1 && x < mark->right->data) {
        mark->right = singleRotateLeft(mark->right);
        return singleRotateRight(mark);
    }
    return mark;
}
void display(node* t) {
    if (t != NULL) {
        display(t->left);
        std::cout << t->data << ' ';
        display(t->right);
    }
}
int main(int argc, char const *argv[]) {
    node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    display(root);
    return 0;
}
