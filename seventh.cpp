#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* head;
void detectLoop() {
    int count = 1;
    node* slow_t = head;
    node* fast_t = head;
    do{
        slow_t = slow_t->next;
        fast_t = fast_t->next->next;
    }while (slow_t != fast_t);
    slow_t = head;
    while (slow_t != fast_t) {
        slow_t = slow_t->next;
        fast_t = fast_t->next;
        count++;
    }
    std::cout << "The starting point is at node "<< count<<" The value of the node is " <<slow_t->data<< '\n';
}
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
int main(int argc, char const *argv[]) {
    node* temp = getNewNode(5);
    node* ptr;
    head = temp;
    temp->next = getNewNode(10);
    temp = temp->next;
    temp->next = getNewNode(15);
    temp = temp->next;
    temp->next = getNewNode(20);
    temp=temp->next;
    temp->next = getNewNode(25);
    temp=temp->next;
    ptr = temp;
    temp->next = getNewNode(30);
    temp=temp->next;
    temp->next = getNewNode(35);
    temp=temp->next;
    temp->next = getNewNode(40);
    temp=temp->next;
    temp->next = ptr;
    detectLoop();git add
    return 0;
}
