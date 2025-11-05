#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, w[10101], dp[10101];

int go() {
    dp[1] = w[1];
    dp[2] = w[1] + w[2];
    for (int i = 3; i <= n; i++) {
        int xoo = dp[i-3] + w[i-1] + w[i];
        int xo = dp[i-2] + w[i];
        int ox = dp[i-1];
        dp[i] = max(xoo, max(xo, ox));
    }

    return dp[n];
}

int main(void) {
    fastIO;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cout << go();

    return 0;
}