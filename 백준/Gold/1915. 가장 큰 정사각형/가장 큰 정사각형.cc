#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, res = 0;
int dp[1010][1010], v[1010][1010];

void go() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == 1)
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            else dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res = max(res, dp[i][j]);
        }
    }
}

int main(void) {
    fastio();
    cin >> n >> m;

    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= m; j++)
            v[i][j] = str[j-1] - '0';
    }
    
    go();
    cout << res * res << '\n';
    return 0;
}