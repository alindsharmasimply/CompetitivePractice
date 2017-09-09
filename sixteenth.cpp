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
void display() {
    node* temp = head;
    do
    {
        std::cout << temp->data << '\n';
        temp = temp->next;
    }while (temp != head);
}
void insertAttheStart(int x)
{
    node* temp1 = getNewNode(x);
    if (head == NULL) {
        head = temp1;
        temp1->next = head;
        return;
    }
    node* temp = head;
    temp1->next = head;
    while (temp->next != head) {
        temp =temp->next;
    }
    temp->next = temp1;
    head = temp1;
}
void problem(int m, node* t) {
    node* temp = t;
    if (temp->next == head) {
        return;
    }
    else{
        node* temp1;
        int i = 0;
    while (i < m-2) {
        temp1 = temp;
        temp = temp->next;
        i++;
    }
    temp1->next = temp1->next->next;
    delete temp;
    head = temp1->next;
    problem(m, head);
}
}
int main(int argc, char const *argv[]) {
    head = NULL;
    insertAttheStart(7);
    insertAttheStart(6);
    insertAttheStart(5);
    insertAttheStart(4);
    insertAttheStart(3);
    insertAttheStart(2);
    insertAttheStart(1);
    display();
    problem(3, head);
    std::cout << '\n';
    std::cout << "The elected head will be "<< head->data << '\n';
    return 0;
}
