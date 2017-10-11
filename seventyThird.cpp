#include <iostream>
#include <deque>
using namespace std;
deque<char> D;
int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    char ch;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i];
        if (ch == '<') {
            D.pop_back();
        }
        else
            D.push_back(ch);
    }
    while (!D.empty()) {
        cout << D.front();
        D.pop_front();
    }
    return 0;
}
