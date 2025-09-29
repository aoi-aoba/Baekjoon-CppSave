#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int t, n;
const int MOD = 1e9 + 7;

ll modpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if ((exp & 1) == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        cout << modpow(2, n - 2) << "\n";
    }

    return 0;
}