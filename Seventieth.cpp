#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    long maxi = 0;
    long k;
    int count = 1;
    cin >> n;
    for(int i=0; i<n; i++)
    {cin >> k;
     if (maxi < k)
     {    maxi = k;
      count = 1;
     }
     else if(maxi == k)
         count++;
    }
    cout << count;
    return 0;
}
