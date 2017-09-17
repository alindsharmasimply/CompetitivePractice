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
node* root = getNewNode(100);
queue<node*> Q;
void create() {
    root->right = getNewNode(70);
    root->left = getNewNode(30);
    root->right->right = getNewNode(80);
    root->right->left = getNewNode(60);
    root->left->left = getNewNode(20);
    root->left->right = getNewNode(40);
}
node* insert(node* t, int n)
{
    if (t == NULL) {
        return getNewNode(n);
    }
    if (t->data > n) {
        t-> left = insert(t->left, n);
    }
    else{
        t->right = insert(t->right, n);
    }
    return t;
}
void display(){
    node* temp;
    Q.push(root);
    while (!Q.empty()) {
        temp = Q.front();
        Q.pop();
        cout << temp->data << ' ';
        if (temp->left != NULL) {
            Q.push(temp->left);
        }
        if (temp->right != NULL) {
            Q.push(temp->right);
        }
    }
}
int main(int argc, char const *argv[]) {
    int n;
    std::cout << "Enter a number to insert" << '\n';
    std::cin >> n;
    insert(root , n);
    insert(root, n+10);
    insert(root, n+40);
    insert(root, n-20);
    insert(root, n+80);
    insert(root, n-60);
    insert(root, n+50);
    insert(root, n-30);
    insert(root, n+70);
    display();
    std::cout  << '\n';
    std::cout << root->left->right->data << '\n';
    return 0;
}
