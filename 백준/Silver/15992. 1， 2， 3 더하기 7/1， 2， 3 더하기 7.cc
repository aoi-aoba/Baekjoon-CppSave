#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MOD 1000000009
using namespace std;

int t, n, m;
ll dp[1010][1010];

void go(int n, int m) {
    dp[1][1] = dp[2][1] = dp[3][1] = dp[2][2] = dp[3][3] = 1;
    dp[3][2] = 2;
    for (int i = 4; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1]) % MOD;
        }
    }
}

int main(void) {
    fastIO;
    cin >> t;
    go(1000, 1000);
    while (t--) {
        cin >> n >> m;
        cout << (int)(dp[n][m]) << '\n'; 
    }
    return 0;
}

/*
dp[p][q] = dp[p-1][q-1] + dp[p-2][q-1] + dp[p-3][q-1]
		(p-1 + 1로 나타낸 뒤, p-1을 q-1개로 나타내는 경우의 수)
		(p-2 + 2로 나타낸 뒤, p-2를 q-1개로 나타내는 경우의 수)
		(p-3 + 3으로 나타낸 뒤, p-3을 q-1개로 나타내는 경우의 수)
*/