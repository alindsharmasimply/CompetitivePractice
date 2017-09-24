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
    node* temp = root;
    if (temp == NULL) {
        temp = getNewNode(x);
    }
    else{
        node* mark;
        node* temp1 = temp;
        while (temp1 != NULL) {
            if (temp1->data > x) {
                mark = temp1;
                temp1 = temp1->left;
            }
            else if (temp1->data < x) {
                mark = temp1;
                temp1 = temp1->right;
            }
        }
        if (mark->data > x) {
            mark->left = getNewNode(x);
        }
        else
            mark->right = getNewNode(x);
    }
    root = temp;
}
void display(node* t) {
    if (t != NULL) {
        display(t->left);
        std::cout << t->data << ' ';
        display(t->right);
    }
}
void findMax()
{
    node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    std::cout << "The maximum number is "<< temp->data << '\n';
}
int main(int argc, char const *argv[]) {
    root = NULL;
    insert(4);
    insert(5);
    insert(8);
    insert(6);
    insert(45);
    insert(10);
    insert(32);
    insert(55);
    insert(28);
    insert(13);
    insert(9);
    display(root);
    std::cout << '\n';
    findMax();
    return 0;
}
