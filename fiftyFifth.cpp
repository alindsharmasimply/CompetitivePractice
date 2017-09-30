#include <iostream>
using namespace std;
struct tnode {
    int data;
    tnode* right;
    tnode* left;
};
struct lnode {
    int data;
    lnode* next;
};
lnode* head;
tnode* root;
tnode* getNewNodeTree(int x)
{
    tnode* temp = new tnode();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
lnode* getNewNodeList(int x)
{
    lnode* temp = new lnode();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert(int x, int n)
{
    lnode* temp = getNewNodeList(x);
    if (n == 1) {
        temp->next = head;
        head = temp;
    }
    else
    {
        lnode* temp1 = head;
        for (int i = 0; i < n - 2; i++) {
            temp1 = temp1 -> next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}
void display(/* arguments */) {
    lnode* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
}
tnode* listToTree(lnode* h, int n) {
    if (n <= 0) {
        return NULL;
    }
    tnode* left = listToTree(h, n/2);
    tnode* roo = getNewNodeTree(h->data);
    roo->left = left;
    h = h->next;
    roo->right = listToTree(h, n - n/2 -1);
    return roo;
}
void countNodes() {
    lnode* temp = head;
    int n = 0;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    root = listToTree(head, n);
}
void displayTree(tnode* t) {
    if (t != NULL) {
        displayTree(t->left);
        std::cout << t->data << ' ';
        displayTree(t->right);
    }
}
int main(int argc, char const *argv[]) {
    head = NULL;
    root = NULL;
    insert(1,1);
    insert(2,2);
    insert(3,3);
    insert(4,4);
    insert(5,5);
    insert(6,6);
    insert(7,7);
    insert(8,8);
    display();
    std::cout  << '\n';
    countNodes();
    displayTree(root);
    return 0;
}
