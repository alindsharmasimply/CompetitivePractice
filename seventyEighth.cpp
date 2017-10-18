#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
    int n, x, y, k;
    cin >> n;
    char choice;
    int count = 0;
    vector<long> d(n, 0);
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> choice;
        if (choice == 'F') {
            cin >> x;
            if (d[x-1] == 0) {
                d[x-1] = 1;
            }
            else
            {
                d[x-1] = 0;
            }
        }
        else
        {
            cin >> x >> y;
            for (int j = x-1; j < y; j++) {
                if(d[j] == 1)
                {
                    count++;
                }
            }
            std::cout << count << '\n';
            count = 0;
        }
    }
    return 0;
}
