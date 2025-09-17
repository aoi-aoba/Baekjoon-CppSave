#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int k, n;
ll res = 0;
vector<int> lines;

ll f(ll x) {
    ll tot = 0;
    for (int temp : lines)
        if (temp >= x)
            tot += temp / x;
    return tot;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        lines.push_back(x);
    }

    sort(lines.begin(), lines.end());

    ll s = 0, e = 2147483647, mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (f(mid) >= n) {
            res = max(res, mid);
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    cout << res << '\n';

    return 0;
}