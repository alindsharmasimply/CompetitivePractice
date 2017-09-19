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

int level = 0;
int currentSum = 0;
int maxSum = 0;
int maxLevel = 0;
queue<node*> Q;
node* root = getNewNode(10);

void create() {
    root->right = getNewNode(30);
    root->left = getNewNode(20);
    root->right->right = getNewNode(70);
    root->right->right->left = getNewNode(65);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(40);
    root->left->right = getNewNode(50);
}

void sumlevelOrder(node* t) {
    node* temp;
    Q.push(t);
    Q.push(NULL);
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if (temp == NULL) {
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxLevel = level;
            }
            currentSum = 0;
            if (!Q.empty()) {
                Q.push(NULL);
            }
            level++;
        }
        else{
            currentSum = currentSum + temp->data;
            if (temp->left) {
                Q.push(temp->left);
            }
            if (temp->right) {
                Q.push(temp->right);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    create();
    sumlevelOrder(root);
    std::cout << "The largest sum is as follows " << '\n';
    std::cout << maxSum << '\n';
    std::cout << "The level with the largest sum is " << '\n';
    std::cout << maxLevel << '\n';
    return 0;
}
