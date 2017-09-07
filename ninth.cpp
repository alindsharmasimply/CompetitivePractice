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
void problem(/* arguments */) {
    int x1=0, x2=0, d=0, f=0;
    node* temp1 = head1;
    node* temp2 = head2;
    while (true) {
        if(temp1 == NULL)
        {
            break;
        }
        temp1 = temp1 -> next;
        x1 = x1 + 1;
    }

    while (true) {
        if(temp2 == NULL)
        {
            break;
        }
        temp2 = temp2 -> next;
        x2 = x2 + 1;
    }
    if (x1 > x2) {
        f = 1;
        d = x1 - x2;
    }
    else
        d = x2 - x1;
    if(f == 1)
    {
    for (int i = 0; i <= d; i++) {
        temp1 = temp1->next;
    }
    while (temp1 == temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    std::cout << "The value of the merge point is "<< temp1->data << '\n';
}
}
void last(/* arguments */) {
    node* temp = head2;
    node* tt = head1;
    while (temp->next != NULL) {
        temp = temp->next;
        tt = tt->next;
    }
    temp->next = tt -> next;
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
    display1();
    std::cout << '\n';
    display2();
    std::cout  << '\n';
    last();
    problem();
    return 0;
}
