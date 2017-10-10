#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
    int a[] = {20, 40,12,60,30,90,25};
    vector<int> v(a, a + 7);
    std::vector<int>:: iterator found;
    found = find(v.begin(), v.end(), 30);
    std::cout << "The number is found at "<< (found- v.begin()+1) << '\n';
    return 0;
}
