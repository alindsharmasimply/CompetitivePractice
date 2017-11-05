#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, count = 0;
    long long k;
    long long x, sum = 0;
    std::vector<long long> v;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x <= k) {
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (sum <= k) {
            count++;
        }
    }
    std::cout << count << '\n';
    return 0;
}
