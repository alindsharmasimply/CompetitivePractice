#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* head;
node* second_Half;
bool palin = false;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert(int x, int n) {
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
void reverse(node** hh) {
    node* prev = NULL;
    node* current = *hh;
    node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *hh = prev;
}
bool compareLists(){
    node* temp1 = head;
    node* temp2 = second_Half;
    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        return false;
    }
    if (temp1 == NULL && temp2 == NULL) {
        return true;
    }
    return false;
}
void problem() {
    node* slowP = head;
    node* fastP = head;
    node* slow_Prev;
    node* midnode = NULL;
    while(fastP != NULL && fastP->next != NULL) {
        fastP = fastP->next->next;
        slow_Prev = slowP;
        slowP = slowP->next;
    }

    if (fastP != NULL) {
        midnode = slowP;
        slowP = slowP->next;
    }

    second_Half = slowP;
    slow_Prev->next = NULL;

    reverse(&second_Half);
    palin = compareLists();
    if (midnode != NULL) {
        slow_Prev->next = midnode;
        midnode->next = second_Half;
    }
    else{
        slow_Prev->next = second_Half;
    }
    if (palin == true) {
        std::cout << "The list is a palindrome " << '\n';
    }
    else{
        std::cout << "The list is not a palindrome " << '\n';
    }
}
int main(int argc, char const *argv[]) {
    head = NULL;
    insert(2,1);
    insert(3,2);
    insert(6,3);
    insert(8,4);
    insert(8,5);
    insert(6,6);
    insert(4,7);
    insert(2,8);
    problem();
    return 0;
}
