#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    std::vector<int> v(n);
    int count = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int x = v[0];
    int y = v[0] + 4;
    for (int i = 1; i < n; i++) {
        if(v[i] >= x && v[i] <= y)
            continue;
        else
        {
            count++;
            x = v[i];
            y = v[i] + 4;
        }
    }
    std::cout << count << '\n';
    return 0;
}
