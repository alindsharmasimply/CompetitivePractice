#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
    map<string, vector<int> > trips;
    int n,m,k;
    string name;
    int year;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> year;
        trips[name].push_back(year);
    }
    for (map<string, vector<int> >:: iterator it = trips.begin(); it != trips.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> name >> k;
        cout << trips[name][k-1] << '\n';
    }
    return 0;
}
