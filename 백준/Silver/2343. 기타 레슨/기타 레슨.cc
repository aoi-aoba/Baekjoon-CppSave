#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

vector<ll> v;

ll f(ll x) {
    ll cnt = 0, sum = 0;
    for (int val : v) {
        if (sum + val > x) {
            sum = 0;
            cnt++;
        }
        sum += val;
    }
    if (sum != 0) cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    ll left = 0, right = 0, mid;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        left = max(left, x);
        right += x;
        v.push_back(x);
    }

    while (left <= right) {
        mid = (left + right) / 2;
        if (f(mid) <= m) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << '\n';
    
    return 0;
}