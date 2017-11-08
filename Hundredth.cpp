#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    string s;
        deque<char> D;
        cin >> s;
        D.push_back(s[0]);
        for (int j = 1; j < s.size(); j++) {
            if (D.back() == s[j]) {
                D.pop_back();
            }
            else
            {
                D.push_back(s[j]);
            }
        }
        if (D.empty()) {
            std::cout << "Empty String" << '\n';
        }
        else{
            while(!D.empty()) {
                cout << D.front();
                D.pop_front();
            }
        }
    return 0;
}
