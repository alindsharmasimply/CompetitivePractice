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
void insert(node* tt, int x) {
    if (tt == NULL) {
        tt = getNewNode(x);
    }
    else{
        node* mark;
        node* ttt = tt;
        while (ttt != NULL) {
            if (ttt->data < x){
                mark = ttt;
                ttt = ttt->right;
            }
            else if (ttt->data > x ) {
                mark = ttt;
                ttt = ttt->left;
            }
        }
    if (mark->data > x) {
        mark->left = getNewNode(x);
    }
    else
        mark->right = getNewNode(x);
}
root = tt;
}
void display(node* tt) {
    if (tt != NULL) {
        display(tt->left);
        std::cout << tt->data << " ";
        display(tt->right);
    }
}
void find(int x) {
    node* temp = root;
    if (temp == NULL) {
        std::cout << "No tree" << '\n';
    }
    else
    {
        while(temp != NULL)
        if (temp->data == x) {
            std::cout << "Element is found." << '\n';
            break;
        }
        else if (temp->data > x) {
            temp = temp->left;
        }
        else
        temp = temp->right;
    }
}
int main(int argc, char const *argv[]) {
    root = NULL;
    insert(root, 6);
    insert(root, 7);
    insert(root, 4);
    insert(root, 3);
    insert(root, 2);
    insert(root, 8);
    insert(root, 1);
    insert(root, 5);
    insert(root, 222);
    display(root);
    std::cout << '\n';
    find(3);
    return 0;
}
