#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
    long long a[5];
    long long maximum = 0, minimum = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> a[i];
    }
    sort(a, a + 5);
    for (int i = 0; i < 4; i++) {
        minimum = minimum + a[i];
        maximum = maximum + a[i+1];
    }
    std::cout << minimum << ' ' << maximum;
    return 0;
}
