#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;

int main(void) {
    fastio;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());

    int cur = -1, ans = 0;
    for (auto p : v) {
        int e = p.first, s = p.second;
        if (cur <= s) {
            ans++;
            cur = e;
        }
    }
    cout << ans;
    return 0;
}