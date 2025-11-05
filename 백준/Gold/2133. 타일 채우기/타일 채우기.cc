#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, dp[31];

void go() {
    dp[0] = dp[1] = 0;
    dp[2] = 3;
    for (int i = 3; i <= 30; i++) {
        if (i % 2 != 0) dp[i] = 0;
        else {
            dp[i] += 3 * dp[i-2] + 2; // 끝에 3*2 붙이는 것 + 특수케이스
            int j = i - 2;
            while (j > 0) {
                j -= 2;
                dp[i] += 2 * dp[j];
            }
        }
    }
}

int main(void) {
    fastio();
    cin >> n;
    go();
    cout << dp[n];
    return 0;
}