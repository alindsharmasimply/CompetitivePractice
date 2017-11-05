#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k, x, f, imp = 0, un_imp = 0;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> f;
        if (f == 1) {
            v.push_back(x);
            imp = imp + x;
        }
        else
            un_imp = un_imp + x;
        }
        int s = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < (s - k); i++) {
            imp = imp - (2 * v[i]);
        }
        std::cout << imp + un_imp << '\n';
    return 0;
}
