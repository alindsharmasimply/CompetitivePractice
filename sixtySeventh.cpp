#include <iostream>
using namespace std;
short parity(unsigned long x)
{
    int result = 0;
    while (x) {
        result = result + (x & 1);
        x = x >> 1;
    }
    return result % 2;
}
int main(int argc, char const *argv[]) {
    std::cout << "Enter the binary number " << '\n';
    unsigned long x;
    std::cin >> x;
    std::cout << '\n';
    std::cout << "The parity is " << ' ' << parity(x);
    return 0;
}
