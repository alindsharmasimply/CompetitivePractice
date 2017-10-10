#include <iostream>
using namespace std;
short parity(unsigned long x) {
    short result = 0;
    while (x) {
        result = result ^ 1;
        x = x & (x - 1);
    }
    return result;
}
int main(int argc, char const *argv[]) {
    unsigned long x;
    std::cin >> x;
    std::cout << "The parity is " << ' '<< parity(x);
    return 0;
}
