#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(int a, int b, int c)
{
    return (b + a) > c;
}

int main() {
    int n;
    cin >> n;
    std::vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<long long>());
    for (int i=2; i<n; i++)
    {
    if (isValid(v[i], v[i - 1], v[i - 2])) {
        std::cout << v[i] << " " << v[i-1] << " " << v[i-2];
        return 0;
    }
}
        std::cout << -1 << '\n';
    return 0;
}
