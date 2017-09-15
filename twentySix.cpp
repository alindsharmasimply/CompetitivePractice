#include <iostream>
#include <stack>
#include <queue>
using namespace std;
queue<int> Q;
stack<int> ST;
void problem() {
    int half = Q.size() / 2;

    for (int i = 0; i < half; i++) {
        ST.push( Q.front() );
        Q.pop();
    }

    while (!ST.empty()) {
        Q.push( ST.top() );
        ST.pop();
    }

    for (int i = 0; i < half; i++) {
        Q.push( Q.front() );
        Q.pop();
    }

    for (int i = 0; i < half; i++) {
        ST.push( Q.front() );
        Q.pop();
    }

    while (!ST.empty()) {
        Q.push( ST.top() );
        ST.pop();
        Q.push( Q.front() );
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
    Q.push(19);
    Q.push(20);
    problem();
    int l = Q.size();
    for (int i = 0; i < l; i++) {
        cout << Q.front() << endl;
        Q.pop();
    }
    return 0;
}
