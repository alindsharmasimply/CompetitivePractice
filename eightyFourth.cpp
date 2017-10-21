#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, t, x, i, j;
    int min = 100000;
    cin >> n >> t;
    vector<int> freeway;
    for(int k=0; k<n; k++)
    {
        cin >> x;
        freeway.push_back(x);
    }
    for(int p = 0; p<t; p++)
    {
        cin >> i >> j;
        for(int q = i; q <= j; q++)
        {
            if(min > freeway[q])
                min = freeway[q];
        }
        if(min >= 3)
            cout << 3 << endl;
        else if(min >= 2)
            cout << 2 << endl;
        else if(min >= 1)
            cout << 1 << endl;
        min = 100000;
    }
    return 0;
}
