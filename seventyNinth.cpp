#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count_Digits(long n)
{
    int countDivisibility = 0;
    long c = n;
    long d;
    while(n != 0)
    {
        d = n % 10;
        if(d != 0)
            if(c % d == 0)
            {
                countDivisibility++;
            }
        n = n / 10;
    }
    return countDivisibility;
}

int main() {
    int T;
    long n;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> n;
        cout << count_Digits(n) << endl;
    }
    return 0;
}
