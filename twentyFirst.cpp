#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* top;
node* getNewNode(int x)
{
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
int pop(/* arguments */) {
    node* temp = top;
    top = top->next;
    return temp->data;
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
    int n[10];
    std::cout << "Enter the values " << '\n';
    for (int i = 0; i < 10; i++) {
        cin >> n[i];
        push(n[i]);
    }
    display();
    std::cout << '\n';
    for (int i = 0; i < 10; i++) {
        n[i] = pop();
        std::cout << n[i] << '\n';
    }
    return 0;
}
