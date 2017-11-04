#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[]) {
    int n, k = 0;
    long long sum = 0;
    cin >> n;
    std::vector<int> cake(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cake[i];
    }
    sort(cake.begin(), cake.end());
    for(int j = n - 1; j >= 0; j--)
    {
        sum = sum + (cake[j] * pow(2, k));
        k++;
    }
    std::cout << sum << '\n';
    return 0;
}
