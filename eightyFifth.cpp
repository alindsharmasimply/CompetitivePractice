#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    int count = 1;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(isupper(s[i]))
            count++;
    }
    cout << count;
    return 0;
}
