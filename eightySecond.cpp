#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, x;
    cin >> n;
    vector<int> stick;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        stick.push_back(x);
    }
    sort(stick.rbegin(), stick.rend());
    while(!stick.empty())
    {
        cout << stick.size() << endl;
        for(int i = 0; i < stick.size(); i++)
        {
            stick[i] = stick[i] - stick[stick.size() - 1];
        }
        while(stick.back() == 0 && !stick.empty())
        {
            stick.pop_back();
        }
    }
    return 0;
}
