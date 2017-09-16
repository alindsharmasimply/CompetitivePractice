#include <iostream>
using namespace std;
struct node{
    int data;
    node* right;
    node* left;
};
int largest = 10;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* root = getNewNode(10);
void maximum(node* t) {
    if (t == NULL) {
        return;
    }
    if (t->data > largest) {
        largest = t->data;
    }
    maximum(t->left);
    maximum(t->right);
}
void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}
int main(int argc, char const *argv[]) {
    create();
    maximum(root);
    std::cout << "The maximum number is " << largest << '\n';
    return 0;
}
