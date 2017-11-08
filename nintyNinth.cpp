#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s = "hackerrank";
    int n, k;
    string x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        k = 0;
        for (int j = 0; j < x.length(); j++) {
            if (s[k] == x[j]) {
                k++;
            }
    }
    if (k == 1) {
        cout << "YES" << '\n';
    }
    else
        std::cout << "NO" << '\n';
}
    return 0;
}
