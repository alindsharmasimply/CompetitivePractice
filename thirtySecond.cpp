#include <iostream>
#include <queue>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
queue<node*> Q;
int largest = 0;
node* getNewNode(int x) {
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
node* root = getNewNode(10);
void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}
void maximum() {
    node* temp;
    Q.push(root);
    while (!Q.empty() ) {
        temp = Q.front();
        Q.pop();
        if (temp->data > largest) {
            largest = temp->data;
        }
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
    maximum();
    std::cout << "The largest number is " << largest<< '\n';
    return 0;
}
