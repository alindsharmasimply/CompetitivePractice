#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* head;
node* getNewNode(int x){
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert(int x,int n)
{
    node* newNode = getNewNode(x);
    node* temp2;
    if(n == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        node* temp1 = head;
        for (int i = 0; i < n-1; i++) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        newNode->next = temp1;
        temp2->next = newNode;
    }
}
void remove(int n) {
    node* tempt;
    node* temp = head;
    for (int i = 0; i < n-1; i++) {
        tempt = temp;
        temp = temp->next;
    }
    tempt->next = temp->next;
    delete temp;
}
void display() {
    node* temp3 = head;
    while (temp3 != NULL) {
        std::cout << temp3->data << '\n';
        temp3 = temp3->next;
    }
}
int main(int argc, char const *argv[]) {
    head = NULL;
    insert(3,1);
    insert(6,2);
    insert(4,2);
    insert(5,3);
    display();
    std::cout << '\n';
    remove(3);
    display();
    return 0;
}
