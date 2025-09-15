#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int n;
ll m;
vector<int> arr;

ll f(ll x) {
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) tot += arr[i] - x;
    }
    return tot;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    ll s = 0, e = 1000000000;
    ll ans = 0;
    while (s <= e) {
        ll x = (s + e) / 2;
        if (f(x) >= m) {
            ans = x;
            s = x + 1;
        } else {
            e = x - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}