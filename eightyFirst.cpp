#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, x;
    int jump = 0;
    cin >> n;
    vector<int> cloud;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cloud.push_back(x);
    }
    for(int i = 0; i < n-1;)
    {
        if(cloud[i + 2] == 0)
        {
            i += 2;
        }
        else if(cloud[i + 1] == 0)
        {
            i += 1;
        }
        jump++;
    }
    cout << jump;
    return 0;
}
