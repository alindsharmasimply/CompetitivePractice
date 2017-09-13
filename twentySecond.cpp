#include <iostream>
using namespace std;
int rear = -1;
int front = -1;
int a[10];
void enqueue(int x) {
    if (rear == -1 && front == -1) {
        rear = front = 0;
    }
    else{
        rear = (rear + 1) % 10;
    }
    a[rear] = x;
}
int dequeue()
{
    int c = front;
    front = (front + 1) % 10;
    return a[c];
}
void display(/* arguments */) {
    for (int i = 0; i < 10; i++) {
        std::cout << a[(front + i) % 10] << '\n';
    }
}
int main(int argc, char const *argv[]) {
    enqueue(5);
    display();
    cout << "\n";
    enqueue(10);
    display();
    cout << "\n";
    enqueue(15);
    display();
    cout << "\n";
    enqueue(20);
    display();
    cout << "\n";
    enqueue(25);
    display();
    cout << "\n";
    dequeue();
    display();
    cout << "\n";
    return 0;
}
