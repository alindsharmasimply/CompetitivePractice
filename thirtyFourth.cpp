#include <iostream>
#include <queue>
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
queue<node*> Q;
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
void searchLevelOrder(int s) {
    Q.push(root);
    node* temp;
    while(!Q.empty())
    {
        temp = Q.front();
        if (temp->data == s) {
            flag = 1;
        }
        Q.pop();
        if (temp->left != NULL) {
            Q.push(temp->left);
        }
        if (temp->right != NULL) {
            Q.push(temp->right);
        }
    }
}
int main(int argc, char const *argv[]) {
    create();
    int x;
    std::cout << "Enter the element to be searched " << '\n';
    std::cin >> x;
    searchLevelOrder(x);
    if (flag == 1) {
        std::cout << "Element is found" << '\n';
    }
    else
    std::cout << "Element is not found" << '\n';
    return 0;
}
