#include <iostream>
#include <stack>
#include <queue>
using namespace std;
queue<int> Q;
stack<int> st;
void problem()
{
    while( !Q.empty() ){
        st.push(Q.front());
        Q.pop();
    }
    while ( !st.empty() ) {
        Q.push(st.top());
        st.pop();
    }
}
void display() {
    while (!Q.empty()) {
        cout << Q.front() << '\n';
        Q.pop();
    }
}
int main(int argc, char const *argv[]) {
    Q.push(11);
    Q.push(22);
    Q.push(33);
    Q.push(44);
    Q.push(55);
    Q.push(66);
    Q.push(77);
    problem();
    display();
    return 0;
}
