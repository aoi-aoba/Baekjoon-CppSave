#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        auto itr = lower_bound(v.begin(), v.end(), x);
        if (*itr == x && itr != v.end()) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}