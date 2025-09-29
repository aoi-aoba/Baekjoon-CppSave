#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, r;
const int MOD = 1000000007;
vector<ll> facts;

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

ll modinv(ll n) {
    return modpow(n, MOD - 2);
}

void preFacts(int n) {
    facts.resize(n + 1, 1);
    for (int i = 2; i < n + 1; i++)
        facts[i] = ((ll)facts[i-1] * i) % MOD;
}

int combMod(int n, int r) {
    if (r > n) return 0;
    preFacts(n);
    return facts[n] * modinv(facts[r]) % MOD * modinv(facts[n - r]) % MOD;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r;
    cout << combMod(n, r);
    
    return 0;
}