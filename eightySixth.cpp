#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


int main() {
    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(),::tolower);
    set<char> cc;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            continue;
        }
        else
            cc.insert(s[i]);
    }
    if (cc.size() == 26) {
        cout<< "pangram" << endl;
    }
    else
        cout << "not pangram" << endl;
    return 0;
}
