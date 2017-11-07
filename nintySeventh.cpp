#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, count;
    cin >> n;
    string s;
    char ch;
    for (int i = 0; i < n; i++) {
        cin >> s;
        count = 0;
        ch = s[0];
        for (int j = 1; j < s.length(); j++) {
            if (s[j] == ch) {
                count++;
            }
            else
                {
                    ch = s[j];
                }
        }
        std::cout << count << '\n';
    }
    return 0;
}
