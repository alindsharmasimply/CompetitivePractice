#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* top;
node* getNewNode(int x) {
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void push(int x) {
    node* temp = getNewNode(x);
    temp->next = top;
    top = temp;
}
int pop() {
    int d = top->data;
    node* temp = top;
    top = top->next;
    delete temp;
    return d;
}
void display(/* arguments */) {
    node* temp = top;
    while (temp != NULL) {
        std::cout << temp->data << '\n';
        temp = temp->next;
}
}
int main(int argc, char const *argv[]) {
    top = NULL;
    int x,z;
    std::cout << "Enter the values to be pushed " << '\n';
    while (true) {
        std::cin >> x;
        if (x == 0) {
            break;
        }
        push(x);
    }
    std::cout << '\n';
    display();
    std::cout <<"Enter 1 to pop and 0 to stop" << '\n';
    while (true) {
        std::cin >> z;
        if (z == 0) {
            break;
        }
        std::cout << "The popped value is " << pop() <<"\n";
    }
    display();
    return 0;
}
