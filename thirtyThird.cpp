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
int flag = 0;
node* root = getNewNode(10);
void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}
void searchElement(node* t, int x) {
    if (t == NULL) {
        return;
    }
    if (t->data == x) {
        flag = 1;
    }
    else
    {
        searchElement(t->left, x);
        searchElement(t->right, x);
    }
}
int main(int argc, char const *argv[]) {
    create();
    std::cout << "Enter the element to be searched " << '\n';
    int x;
    std::cin >> x;
    searchElement(root, x);
    if (flag == 1) {
        std::cout << "Element is found" << '\n';
    }
    else
    {
        std::cout << "Element is not found" << '\n';
    }
    return 0;
}
