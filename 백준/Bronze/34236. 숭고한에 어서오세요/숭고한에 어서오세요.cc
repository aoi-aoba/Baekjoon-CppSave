#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << v[n-1] + (v[1] - v[0]);

    return 0;
}