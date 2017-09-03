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
    temp->next = temp;
    return temp;
}
void insertAttheEnd(int x) {
    node* temp1 = getNewNode(x);
    node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = temp1;
    temp1->next = head;
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
void removeAtTheEnd() {
    node* temp = head;
    node* temp1;
    while (temp->next != head) {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = head;
    delete temp;
}
int main(int argc, char const *argv[]) {
    head = NULL;
    insertAttheStart(3);
    std::cout  << '\n';
     display();
    insertAttheStart(2);
    std::cout  << '\n';
     display();
    insertAttheEnd(5);
    std::cout  << '\n';
     display();
    insertAttheEnd(6);
    std::cout  << '\n';
     display();
     std::cout << '\n';
    removeAtTheEnd();
    display();
    return 0;
}
