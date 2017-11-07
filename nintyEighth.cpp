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
    for (int i = 0; i < n; i++) {
        cin >> s;
        count = 0;
        for (int j = 0; j < s.length()/2; j++) {
            count += abs(s[j] - s[s.length() - 1 - j]);
        }
        std::cout << count << '\n';
    }
    return 0;
}
