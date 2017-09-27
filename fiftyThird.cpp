#include <iostream>
#include <queue>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
node* root;
queue<node*> Q;
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
            else
            {
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
void display1() {
    node* temp;
    Q.push(root);
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        std::cout << temp->data << ' ';
        if (temp->left != NULL)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
}
void lca(node* a, node* b) {
    node* temp = root;
    while (1) {
        if (((a->data  < temp->data) && (b->data > temp->data)) || ((a->data > temp->data) && (b->data < temp->data))) {
            std::cout << "The LCA is " << ' ' << temp->data;
            break;
        }
        if (a->data > temp->data) {
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
}
int main(int argc, char const *argv[]) {
    root = NULL;
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insert(10);
    insert(9);
    insert(8);
    insert(7);
    insert(6);
    display(root);
    std::cout << '\n';
    display1();
    std::cout << '\n';
    lca(getNewNode(8), getNewNode(4));
    return 0;
}
