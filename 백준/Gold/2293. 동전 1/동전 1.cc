#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, res;
int dp[10101], cointype[101];

void go() {
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = cointype[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - cointype[i]];
        }
    }
    res = dp[k];
}

int main(void) {
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> cointype[i];
    go();
    cout << res << '\n';
}