#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000003
using namespace std;

int n, k, dp[1010][1010];

void go(int n, int k) {
    for (int i = 0; i <= n; i++) {
        dp[i][1] = i;
        dp[i][0] = 1;
    }
    for (int i = 4; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = (dp[i-2][j-1] % MOD + dp[i-1][j] % MOD) % MOD;
        }
    }
    cout << dp[n][k];
}

int main(void) {
    fastio();
    cin >> n >> k;
    go(n, k);
    return 0;
}