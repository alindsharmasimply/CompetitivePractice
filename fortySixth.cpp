#include <iostream>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
};
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
node* root1 = getNewNode(10);
node* root2 = getNewNode(10);

void create(node* t) {
    t->left = getNewNode(20);
    t->right = getNewNode(30);
    t->left->left = getNewNode(40);
    t->left->right = getNewNode(50);
    t->left->right->left = getNewNode(70);
    t->right->left = getNewNode(60);
    t->right->left->left = getNewNode(80);
}
void create11(node* t) {
    t->left = getNewNode(50);
    t->right = getNewNode(60);
    t->right->right = getNewNode(30);
    t->right->left = getNewNode(80);
    t->left->right = getNewNode(20);
    t->left->right->right = getNewNode(40);
    t->right->left->right = getNewNode(70);
}
int isomorphic(node* root11, node* root22)
{
    if (root11 == NULL && root22 == NULL) {
        return 1;
    }
    if ((!root11 && root22) || (root11 && !root22)) {
        return 0;
    }
    return (isomorphic(root11->left, root22->left) && isomorphic(root11->right, root22->right));
}
int main(int argc, char const *argv[]) {
    create(root1);
    create11(root2);
    if (isomorphic(root1, root2) == 1)
    {
        std::cout << "The trees are isomorphic." << '\n';
    }
    else
    std::cout << "The trees are not isomorphic." << '\n';

    return 0;
}
