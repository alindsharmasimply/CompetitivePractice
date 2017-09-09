#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* head;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert(int n,int x) {
    node* temp = getNewNode(x);
    node* temp1 = head;
    if (n==1) {
        temp->next = head;
        head = temp;
    }
    else
    {
        for (int i = 0; i < n - 2; i++) {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}
void display(/* arguments */) {
    node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << '\n';
        temp = temp->next;
    }
}
node* problem(node* head) {
    node* temp;
    node* temp1;
    if (head->next == NULL || head == NULL) {
        return head;
    }
    else{
        temp = head->next;
        temp1 = head->next->next;
        head->next-> next = head;
        head->next = problem(temp1);
    return temp;
}
}
int main(int argc, char const *argv[]) {
    head = NULL;
    insert(1,2);
    insert(2,4);
    insert(3,6);
    insert(4,8);
    insert(5,10);
    insert(6,12);
    insert(7,14);
    display();
    std::cout << '\n';
    head = problem(head);
    display();
    return 0;
}
