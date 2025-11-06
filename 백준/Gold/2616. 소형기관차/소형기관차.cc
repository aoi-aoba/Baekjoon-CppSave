#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, sum[50101], dp[4][50101];

int main(void) {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    cin >> m;
    for (int i = 1; i < 4; i++) {
        for (int j = i * m; j <= n; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + sum[j] - sum[j-m]);
        }
    }
    cout << dp[3][n];
}