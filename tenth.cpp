#include <iostream>
using namespace std;
struct node{
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
void problem(/* arguments */) {
    node* p1 = head;
    node* p2 = head;
    do {
        p1 = p1->next->next;
        p2 = p2->next;
    } while(p1 -> next != NULL);
    std::cout << "The middle element is " << p2->data<< '\n';
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
    problem();
    return 0;
}
