#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, f;
    cin >> n;
    string s, r;
    for (int i = 0; i < n; i++) {
        cin >> s;
        r = s;
        f = 1;
        reverse(r.begin(), r.end());
        for (int j = 1; j <= s.length()/2; j++) {
            if (abs(int(s[j]) - int(s[j-1])) == abs(int(r[j]) - int(r[j-1]))) {
                continue;
            }
            else{
                cout << "Not Funny" << '\n';
                f = 0;
                break;
            }
        }
        if (f == 1) {
            std::cout << "Funny" << '\n';
        }
    }
    return 0;
}
