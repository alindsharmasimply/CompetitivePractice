#include <iostream>
#include <queue>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
int count = 0;
node* getNewNode(int x) {
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
queue<node*> Q;
node* root = getNewNode(10);
void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->right->left = getNewNode(65);
    root->right->right->right = getNewNode(68);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}
void leaveslevelOrder() {
    node* temp;
    Q.push(root);
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if (!temp->right && !temp->left) {
            count++;
        }
        else{
            if (temp->left != NULL) {
                Q.push(temp->left);
            }
            if (temp->right != NULL) {
                Q.push(temp->right);
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    create();
    leaveslevelOrder();
    std::cout << "The number of leaves is " << '\n';
    std::cout << count << '\n';
    return 0;
}
