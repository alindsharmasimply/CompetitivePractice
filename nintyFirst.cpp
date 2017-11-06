#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    long x, sum = 0;
    cin >> n >> k;
    std::vector<long> v;
    std::vector<int> p(k);
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    int pIndex = 0;
    sort(v.begin(), v.end());
    for (int i = (n-1); i >= 0; i--) {
        sum += (p[pIndex] + 1) * v[i];
        p[pIndex]++;
        pIndex++;
        if (pIndex >= k) {
            pIndex = 0;
        }
    }
    std::cout << sum << '\n';
    return 0;
}
