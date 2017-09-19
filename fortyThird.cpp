#include <iostream>
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
node* root1 =getNewNode(10);
node* root2 =getNewNode(10);

void create(node* roo) {
    roo->right = getNewNode(30);
    roo->left = getNewNode(20);
    roo->right->right = getNewNode(70);
    roo->right->right->left = getNewNode(65);
    roo->right->left = getNewNode(60);
    roo->left->left = getNewNode(40);
    roo->left->right = getNewNode(50);
}
int identical(node* t1, node* t2) {
    if (t1 == NULL && t2 == NULL) {
        return 1;
    }
    if (t1 != NULL || t2 != NULL) {
        return(
            t1->data == t2->data &&
            identical(t1->left, t2->left) &&
            identical(t1->right, t2->right)
        );
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    create(root1);
    create(root2);
    int x = identical(root1, root2);
    if (x == 1) {
        std::cout << "The trees are identical " << '\n';
    }
    else
    std::cout << "The trees are not identical " << '\n';
    return 0;
}
