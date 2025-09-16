#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);
    for (auto temp : v) {
        cout << temp[0] << ' ' << temp[1] << '\n';
    }
}