#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, x;
    cin >> n;
    vector<int> t(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> x;
        t[x]++;
    }
    for (vector<int>:: iterator it= t.begin(); it != t.end(); it++)
    {
        std::cout << *it << '\n';
    }
    return 0;
}
