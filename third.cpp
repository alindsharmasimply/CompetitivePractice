#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
    node* prev;
};
node* head;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void insertAtHead(int x) {
    node* temp1 = getNewNode(x);
    node* temp2 = head;
    if (head == NULL) {
        temp1->next = head;
        head = temp1;
    }
    else{
            temp1->next = head;
            head->prev = temp1;
            head = temp1;
    }
}
void insertAtTail(int x)
{
    node* temp4 = getNewNode(x);
    node* temp3 = head;
    while (temp3->next != NULL) {
        temp3 = temp3->next;
    }
    temp3->next = temp4;
    temp4->prev = temp3;
}
void display() {
    node* temp3 = head;
    while (temp3 != NULL) {
        std::cout << temp3->data << '\n';
        temp3 = temp3->next;
    }
}
void remove(int n) {
    node* del = head;
    if (n==1) {
        head = del -> next;
        head->prev == NULL;
        delete del;
    }
    else
    {
        for (int i = 0; i < n-1; i++) {
            del = del ->next;
        }
        del->next->prev = del->prev;
        del->prev->next = del->next;
        delete del;
    }
}
int main(int argc, char const *argv[]) {
    head = NULL;
    insertAtHead(66);
    insertAtHead(55);
    insertAtHead(44);
    insertAtHead(33);
    insertAtHead(22);
    insertAtHead(11);
    display();
    std::cout  << '\n';
    insertAtTail(77);
    insertAtTail(88);
    insertAtTail(99);
    display();
    remove(1);
    std::cout  << '\n';
    display();
    remove(4);
    std::cout  << '\n';
    display();
    return 0;
}
