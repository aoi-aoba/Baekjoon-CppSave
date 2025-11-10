#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
vector<pair<int, int>> v;

int main(void) {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, 0});
    }
    sort(v.begin(), v.end());
    int ans = 0, cnt = 0;
    for (auto p : v) {
        if (p.second == 0) {
            cnt--;
        } else cnt++;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}