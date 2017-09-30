#include <iostream>
using namespace std;
struct tnode {
    int data;
    node* right;
    node* left;
};
struct lnode {
    int data;
    node* next;
};
lnode* head;
tnode* root;
tnode* getNewNodeTree(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
lnode* getNewNodeList(int x)
{
    node* temp = new node();
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
int countNodes() {
    lnode* temp = head;
    int n;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    root = listToTree(head, n);
}
tnode* listToTree(lnode* head, int n) {
    if (n <= 0) {
        return NULL;
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
    return 0;
}
