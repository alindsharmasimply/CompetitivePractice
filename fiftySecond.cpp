#include <iostream>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
node* root;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
void insert(int x) {
    if (root == NULL) {
        root = getNewNode(x);
    }
    else{
        node* temp = root;
        node* mark;
        while (temp != NULL) {
            if (temp->data > x) {
                mark = temp;
                temp = temp->left;
            }
            else{
                mark = temp;
                temp = temp->right;
            }
        }
        if (mark->data > x) {
            mark->left = getNewNode(x);
        }
        else
            mark->right = getNewNode(x);
    }
}
void display(node* t) {
    if (t != NULL) {
        display(t->left);
        std::cout << t->data << ' ';
        display(t->right);
    }
}
bool isBinarySearchTree(node* t, int minValue, int maxValue)
{
    if (t == NULL) {
        return true;
    }
    else{
        if (t->data > minValue && t->data < maxValue
            && isBinarySearchTree(t->left, minValue, t->data)
            && isBinarySearchTree(t->right, t->data, maxValue)) {
                return true;
        }
        else
        return false;
    }
}
int main(int argc, char const *argv[]) {
    root = NULL;
    insert(4);
    insert(8);
    insert(1);
    insert(9);
    insert(2);
    insert(7);
    insert(6);
    insert(5);
    insert(3);
    insert(10);
    display(root);
    std::cout << '\n';
    std::cout << "The tree is BST:"<< isBinarySearchTree(root, -100, 100) << '\n';
    return 0;
}
