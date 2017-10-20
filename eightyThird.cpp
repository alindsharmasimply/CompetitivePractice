#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
    int n, a;
    cin >> n;
    std::vector<int> v(101, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
    }
    sort(v.begin(), v.end());
    std::cout << n - v[v.size() - 1] << '\n';
    return 0;
}
