#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* head1;
node* head2;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert1(int x,int n) {
    node* temp = getNewNode(x);
    node* temp1 = head1;
    if (n==1) {
        temp->next = head1;
        head1 = temp;
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
void display1() {
    node* temp = head1;
    while (temp != NULL) {
        std::cout << temp->data << '\n';
        temp = temp -> next;
    }
}
void insert2(int x,int n) {
    node* temp = getNewNode(x);
    node* temp2 = head2;
    if (n==1) {
        temp->next = head2;
        head2 = temp;
    }
    else
    {
        for (int i = 0; i < n - 2; i++) {
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }
}
void display2() {
    node* temp = head2;
    while (temp != NULL) {
        std::cout << temp->data << '\n';
        temp = temp -> next;
    }
}
node* merge(node* head1, node* head2) {
    node* result = NULL;
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    if (head1->data < head2->data) {
        result = head1;
        result->next = merge(head1->next, head2);
    }
    else{
        result = head2;
        result->next = merge(head1, head2->next);
    }
    return result;
}
int main(int argc, char const *argv[]) {
    head1 = NULL;
    head2 = NULL;
    insert1(2,1);
    insert1(4,2);
    insert1(6,3);
    insert1(8,4);
    insert1(10,5);
    insert1(12,6);
    insert1(14,7);
    insert2(1,1);
    insert2(2,2);
    insert2(3,3);
    insert2(4,4);
    display1();
    std::cout << '\n';
    display2();
    std::cout  << '\n';
    node* res = merge(head1, head2);
    while (res != NULL) {
        std::cout << res -> data << '\n';
        res = res->next;
    }
}
