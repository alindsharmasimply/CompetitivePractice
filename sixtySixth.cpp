#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
    int T, x[3];
    cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> x[0];
        std::cin >> x[1];
        std::cin >> x[2];
        sort(x, x + 3);
        std::cout << x[1] << '\n';
    }
    return 0;
}
