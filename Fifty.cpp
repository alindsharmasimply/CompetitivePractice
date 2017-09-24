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
void insert(int x) {
    if (root == NULL) {
        root = getNewNode(x);
    }
    else{
        node* mark;
        node* t = root;
        while (t != NULL) {
            if (t->data > x) {
                mark = t;
                t = t->left;
            }
            else
            {
                mark = t;
                t = t->right;
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
void findMin() {
    node* t = root;
        while (t->left != NULL) {
            t = t->right;
        }
        std::cout << "The minimum element is " << t->data << '\n';
}
int main(int argc, char const *argv[]) {
    insert(4);
    insert(5);
    insert(3);
    insert(7);
    insert(12);
    insert(90);
    insert(11);
    insert(8);
    insert(13);
    insert(15);
    display(root);
    std::cout << '\n';
    findMin();
    return 0;
}
