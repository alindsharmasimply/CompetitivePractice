#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> Q;
stack<int> ST;
void problem(int k)
{
    int l = Q.size();
    for (int i = 0; i < k; i++) {
        ST.push(Q.front());
        Q.pop();
    }
    while (!ST.empty()) {
        Q.push(ST.top());
        ST.pop();
    }
    for (int i = 0; i < l - k; i++) {
        Q.push(Q.front());
        Q.pop();
    }
}
void display(/* arguments */) {
    while (!Q.empty()) {
        std::cout << Q.front() << '\n';
        Q.pop();
    }
}
int main(int argc, char const *argv[]) {
    Q.push(11);
    Q.push(12);
    Q.push(13);
    Q.push(14);
    Q.push(15);
    Q.push(16);
    Q.push(17);
    Q.push(18);
    problem(5);
    display();
    return 0;
}
