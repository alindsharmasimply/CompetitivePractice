#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* rear;
node* front;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->next = NULL;
    temp->data = x;
    return temp;
}
void enqueue(int x) {
    node* temp = getNewNode(x);
    if(rear == NULL && front == NULL){
        rear = front = temp;
    }
    else{
        rear -> next = temp;
        rear = temp;
    }
}
void dequeue(/* arguments */) {
    node* temp = front;
    front = front->next;
    delete temp;
}
void display(/* arguments */) {
    node* temp = front;
    while (temp != NULL) {
        std::cout << temp->data << '\n';
        temp = temp->next;
    }
}
int main(int argc, char const *argv[]) {
    rear = front = NULL;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    display();
    std::cout << '\n';
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}
