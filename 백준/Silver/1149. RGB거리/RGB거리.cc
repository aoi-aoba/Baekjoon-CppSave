#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, dp[1010][4], pr[1010][4];

int go() {
    dp[1][1] = pr[1][1];
    dp[1][2] = pr[1][2];
    dp[1][3] = pr[1][3];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = pr[i][1] + min(dp[i-1][2], dp[i-1][3]);
        dp[i][2] = pr[i][2] + min(dp[i-1][1], dp[i-1][3]);
        dp[i][3] = pr[i][3] + min(dp[i-1][1], dp[i-1][2]);
    }
    return min(dp[n][1], min(dp[n][2], dp[n][3]));
}

int main(void) {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3; j++)
            cin >> pr[i][j];
    cout << go();
}