#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cS = count(s.begin(), s.end(), 'S');
    int cO = count(s.begin(), s.end(), 'O');
    std::cout << s.length() - (cS + cO) << '\n';
    return 0;
}
