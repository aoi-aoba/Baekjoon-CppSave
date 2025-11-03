#include <bits/stdc++.h>
using namespace std;

int n, a[1010], dp[1010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        // dp[i] = a[i]를 마지막 원소로 하는 LIS 길이
        // dp[i] = max(dp[j] + 1) s.t a[j] < a[i] (j < i)
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    return 0;
}