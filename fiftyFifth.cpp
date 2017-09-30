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
node* head;
node* root;
node* getNewNodeTree(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
node* getNewNodeList(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert(int x, int n)
{
    node* temp = getNewNodeList(x);
    if (n == 1) {
        temp->next = head;
        head = temp;
    }
    else
    {
        node* temp1 = head;
        for (int i = 0; i < n - 2; i++) {
            temp1 = temp1 -> next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
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
