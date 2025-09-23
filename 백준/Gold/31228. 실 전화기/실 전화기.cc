#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n, k;

ll euclid(ll a, ll b) {
    if (b == 0) return a;
    else return euclid(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if (n <= 4) {
        cout << 0;
        return 0;
    }

    ll gcd = euclid(n, k);
    if (gcd != 1) {
        n /= gcd;
        k /= gcd;
    }
    
    if (k > n / 2) cout << n * (n - k - 1);
    else cout << n * (k - 1);

    return 0;
}