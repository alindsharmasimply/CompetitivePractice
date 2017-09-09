#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* head;
node* head1;
node* head2;
node* getNewNode(int x) {
    node* temp = new node();
    temp -> next = NULL;
    temp->data = x;
    return temp;
}
void insertAttheStart(int x) {
    node* temp = getNewNode(x);
    if (head == NULL) {
        head = temp;
        temp->next = head;
    }
    else{
        temp->next = head -> next;
        head->next = temp;
    }
}
void display() {
    node* temp = head;
    do {
        std::cout << temp->data << '\n';
        temp = temp->next;
    } while(temp != head);
}
void split(){
    node *sptr = head;
    node *fptr = head;
    while(fptr->next != head && fptr->next->next != head) {
        fptr = fptr->next->next;
        sptr = sptr->next;
    }
    if (fptr->next->next == head)
    {
        fptr=fptr->next;
    }
        head1 = head;
        head2 = sptr->next;
        fptr->next = sptr->next;
        sptr->next = head;
}
void display1(/* arguments */) {
    node* temp = head1;
    do {
        std::cout << temp->data << '\n';
        temp = temp->next;
    } while(temp != head1);
}
void display2(/* arguments */) {
    node* temp = head2;
    do {
        std::cout << temp->data << '\n';
        temp = temp->next;
    } while(temp != head2);
}

int main(int argc, char const *argv[]) {
    head = NULL;
    head1 = NULL;
    head2 = NULL;
    insertAttheStart(26);
    insertAttheStart(8);
    insertAttheStart(12);
    insertAttheStart(16);
    insertAttheStart(20);
    insertAttheStart(24);
    display();
    std::cout  << '\n';
    split();
    display1();
    std::cout  << '\n';
    display2();
    std::cout  << '\n';
    return 0;
}
