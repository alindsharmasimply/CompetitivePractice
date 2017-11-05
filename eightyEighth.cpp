#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    std::vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long minimum = abs(v[0] - v[1]);
    long long d;
    for (int i = 1; i < (n-1); i++) {
        d = abs(v[i] - v[i + 1]);
        if (d < minimum) {
            minimum = d;
        }
    }
    std::cout << minimum << '\n';
    return 0;
}
