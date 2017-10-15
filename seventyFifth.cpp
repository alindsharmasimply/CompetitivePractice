#include <iostream>
using namespace std;
int p[1000];
int find(int x)
{
    return (p[x] == x)? x : p[x] = find(p[x]);
}
void unite(int x, int y) {
    p[find(x)] = find(y);
}
int main(int argc, char const *argv[]) {
    int n, m, x, y;
    for (int i = 0; i < 1000; i++) {
        p[i] = i;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        --x;
        --y;
        unite(x, y);
    }
    bool any = false;

    for (int i = 0; i < n; i++) {
        if (find(i) != find(0)) {
            std::cout << i + 1 << '\n';
            any = true;
        }
    }
    if (!any) {
        std::cout << "Connected" << '\n';
    }

    return 0;
}
