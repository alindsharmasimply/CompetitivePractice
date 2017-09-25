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
    node* temp = new node();;
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
        node* temp = root;
        while(temp != NULL)
        {
            if (x > temp->data) {
            mark = temp;
            temp = temp->right;
        }
        else{
            mark = temp;
            temp = temp->left;
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
node* findMin(node* temp) {
    if (temp == NULL) {
        return NULL;
    }
    else{
        while (temp->left != NULL) {
            temp = temp->left;
        }
    }
    return temp;
}
node* remove(node* t, int x) {
    if (t == NULL) {
        return t;
    }
    else if(t->data > x){
        t->left = remove(t->left, x);
    }
    else if (t->data < x) {
        t->right = remove(t->right, x);
    }
    else{
        if (t->right == NULL && t->left == NULL) {
            delete t;
            t = NULL;
        }
        else if(t->right == NULL)
        {
            node* temp = t;
            t = t->left;
            delete temp;
        }
        else if (t->left == NULL) {
            node* temp = t;
            t = t->right;
            delete temp;
        }
        else
        {
            node* temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->right, temp->data);
        }
    }
    return t;
}
int main(int argc, char const *argv[]) {
    root = NULL;
    insert(12);
    insert(16);
    insert(30);
    insert(25);
    insert(22);
    insert(11);
    insert(8);
    insert(28);
    insert(32);
    insert(35);
    display(root);
    std::cout  << '\n';
    remove(root, 28);
    display(root);
    return 0;
}
