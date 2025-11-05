#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000000
using namespace std;

int n, k, dp[1010][1010];

int go(int k, int n) {
    fill(dp[1], dp[1] + 1010, 1);
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i-1][j] + (j == 1 ? 1 : dp[i][j-1])) % MOD;
        }
    }
    return dp[k][n];
}

int main(void) {
    fastIO;
    cin >> n >> k;
    cout << go(k, n) % MOD;
    return 0;
}