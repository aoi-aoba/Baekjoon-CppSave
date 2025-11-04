#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 1e+9
using namespace std;

int n, k, res;
int dp[10101], cointype[101];

int go() {
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = cointype[i]; j <= k; j++) {
            if (cointype[i] == j) dp[j] = 1;
            else dp[j] = min(dp[j], 1 + dp[j - cointype[i]]);
        }
    }
    return dp[k] == MAX ? -1 : dp[k];
}

int main(void) {
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> cointype[i];
    fill(dp, dp+10101, MAX);
    cout << go();
}