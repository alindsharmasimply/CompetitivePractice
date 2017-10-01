#include <iostream>
#include <queue>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
queue<node*> Q;
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
    else
    {
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
        else{
            mark->right = getNewNode(x);
        }
    }
}
void rangeLevelOrder(int k1, int k2) {
    node* temp;
    Q.push(root);
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if (temp->data >= k1 && temp->data <= k2) {
            std::cout << temp->data << ' ';
        }
        if (temp->left != NULL && temp->data >= k1) {
            Q.push(temp->left);
        }
        if (temp->right != NULL && temp->data <= k2) {
            Q.push(temp->right);
        }
    }
}
int main(int argc, char const *argv[]) {
    root = NULL;
    insert(10);
    insert(5);
    insert(8);
    insert(3);
    insert(9);
    insert(12);
    insert(4);
    insert(6);
    insert(7);
    insert(11);
    insert(2);
    rangeLevelOrder(6, 10);
    return 0;
}
