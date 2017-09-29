#include <iostream>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
node* root;
node* start;
node* previous;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->right = NULL;
    temp->left = NULL;
    temp->data = x;
    return temp;
}
void insert(int x)
{
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
            else{
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
void treeToDLL(node* t) {
    if (t->left != NULL) {
        treeToDLL(t->left);
    }
    else{
    if (start == NULL) {
        start = previous = t;
        start->right = start;
        start->left = start;
        std::cout << start->data << '\n';
    }
    else{
        previous->right = t;
        t->right = start;
        previous = previous->right;
    }
    if (t->right != NULL) {
        treeToDLL(t->right);
    }
    else{
        previous->right = start;
        start->left = previous;
    }
}
}
void displayList() {
    node* temp = start;
    do {
        std::cout << temp->data << ' ';
        temp = temp->right;
    } while(temp != start);
}
int main(int argc, char const *argv[]) {
    root = start = previous = NULL;
    insert(10);
    insert(1);
    insert(9);
    insert(2);
    insert(8);
    insert(3);
    insert(7);
    insert(4);
    insert(6);
    insert(5);
    treeToDLL(root);
    displayList();
    return 0;
}
