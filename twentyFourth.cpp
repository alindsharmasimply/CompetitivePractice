#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> Q;
void display() {
    while (!Q.empty()) {
        std::cout << Q.front() << '\n';
        Q.pop();
    }
}
void reverse() {
    stack<int> st;
    while (!Q.empty()) {
        st.push(Q.front());
        Q.pop();
    }
    while (!st.empty()) {
        Q.push(st.top());
        st.pop();
    }
}
int main(int argc, char const *argv[]) {
    Q.push(4);
    Q.push(8);
    Q.push(12);
    Q.push(16);
    Q.push(20);
    Q.push(24);
    std::cout << '\n';
    reverse();
    display();
    return 0;
}
