#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    char ch;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        ch = s[i];
        if((i % 3) == 0 && (ch != 'S'))
            count++;
        if((i % 3 == 1) && (ch != 'O'))
            count++;
        if((i % 3 == 2) && (ch != 'S'))
            count++;
    }
    std::cout << count << '\n';
    return 0;
}
