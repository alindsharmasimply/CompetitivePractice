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
void insert(int x,int n) {
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
void display() {
    node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << '\n';
        temp = temp -> next;
    }
}
void reverse() {
    node* next;
    node* prev;
    node* current;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int main(int argc, char const *argv[]) {
    head = NULL;
    insert(2,1);
    insert(4,2);
    insert(6,3);
    insert(8,4);
    insert(10,5);
    insert(12,6);
    display();
    std::cout  << '\n';
    reverse();
    display();
    return 0;
}
