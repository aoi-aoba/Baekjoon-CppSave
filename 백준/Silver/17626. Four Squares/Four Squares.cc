#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 224
using namespace std;

int n, dp[50101];

int go() {
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int val = 4, j = 1;
        while (j * j <= i) {
            val = min(val, dp[i - j * j] + 1);
            j += 1;
        }
        dp[i] = val;
    }

    return dp[n];
}

int main(void) {
    fastio;
    cin >> n;
    cout << go();
}