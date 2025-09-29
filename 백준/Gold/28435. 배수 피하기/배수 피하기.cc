#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, k, x;
ll ans = 1;
const int MOD = 1e9 + 7;

vector<int> rem;

ll fastModPow(ll base, ll exp) {
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

    cin >> n >> k;
    rem.resize(k, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        rem[x % k]++;
    }

    for (int i = 1; i <= k / 2; i++) {
        int j = k - i;
        if (i > j) continue;
        if (i == j) ans = ans * (1 + rem[i]) % MOD;
        else {
            ll val = (fastModPow(2, rem[i]) + fastModPow(2, rem[j]) - 1 + MOD) % MOD;
            ans = (ans * val) % MOD;
        }
    }

    ans = ans * (1 + rem[0]) % MOD;
    
    ans = (ans - 1 - n) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans;
    return 0;
}