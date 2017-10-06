#include <iostream>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
node* root = getNewNode(50);
void create() {
    root->right = getNewNode(40);
    root->left = getNewNode(10);
    root->right->right = getNewNode(20);
    root->left->left = getNewNode(70);
    root->right->left = getNewNode(30);
    root->left->right = getNewNode(60);
}
node* removeLeaves(node* temp)
{
    if (temp != NULL) {
        if (temp->right == NULL && temp->left == NULL) {
            delete temp;
            return NULL;
        }
        else{
            temp->left = removeLeaves(temp->left);
            temp->right = removeLeaves(temp->right);
        }
    }
    return temp;
}
void display(node* t){
    if(t != NULL)
    {
    display(t->left);
    std::cout << t->data << ' ';
    display(t->right);
}
}
int main(int argc, char const *argv[]) {
    create();
    display(root);
    root = removeLeaves(root);
    std::cout << '\n';
    display(root);
    return 0;
}
