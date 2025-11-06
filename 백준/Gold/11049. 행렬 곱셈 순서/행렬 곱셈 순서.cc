#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1e9

using namespace std;

int n, r, c, sum[501], dp[501][501], mat[501][2];

int main(void) {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r >> c;
        mat[i][0] = r;
        mat[i][1] = c;
    }

    for (int i = 1; i <= n; i++) { // 구간 크기
        for (int j = 1; i + j <= n; j++) { // 구간 시작
            dp[j][i + j] = INF;
            for (int k = j; k <= i + j; k++) { // k 기준 구간 분할
                dp[j][i + j] = min(dp[j][i + j],
                                dp[j][k] + dp[k + 1][i + j] + 
                                mat[j][0] * mat[k][1] * mat[i+j][1]);
            }
        }
    }

    cout << dp[1][n];
    return 0;
}