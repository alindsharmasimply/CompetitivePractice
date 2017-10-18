#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, x, k = 0, pair = 0;
    cin >> n;
    vector<int> c(101, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        c[x]++;
    }
    for (vector<int>:: iterator it= c.begin(); it != c.end(); it++)
    {
        pair = (*it / 2) + pair;
    }
    cout << pair;
    return 0;
}
