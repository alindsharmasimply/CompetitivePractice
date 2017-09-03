#include <iostream> //FACTORIAL
using namespace std;

int factorial(int n)
{
    if (n==0) {
        return 1;
    }
    else if (n==1) {
        return 1;
    }
    else
    {
        return  n * factorial(n-1);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    std::cout << "Enter the number for the factorial" << '\n';
    std::cin >> n;
    std::cout << "The factorial is" << '\n' << factorial(n);
    return 0;
}
