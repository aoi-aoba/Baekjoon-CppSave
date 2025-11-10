#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int n;
vector<array<int, 3>> v;

int main(void) {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a, i + 1});
    }
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if ((ll)a[0] * b[1] == (ll)a[1] * b[0]) return a[2] < b[2];
        return (ll)a[0] * b[1] > (ll)a[1] * b[0];
    });
    for (auto p: v) {
        cout << p[2] << ' ';
    }

    return 0;
}