#include <iostream>
#include <queue>
#include <stack>
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
stack<node*> ST;
node* root = getNewNode(10);
int size = 0;
void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}
void reverselevelOrder() {
    node* temp;
    node* temp1;
    Q.push(root);
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if (temp->right != NULL) {
            Q.push(temp->right);
        }
        if (temp->left != NULL) {
            Q.push(temp->left);
        }
        ST.push(temp);
    }
    while (!ST.empty()) {
        temp1 = ST.top();
        ST.pop();
        std::cout << temp1->data << ' ';
    }
}
int main(int argc, char const *argv[]) {
    create();
    reverselevelOrder();
    return 0;
}
