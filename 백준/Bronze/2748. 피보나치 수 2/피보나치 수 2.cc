#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int n;
ll dp[101];

ll go(int i) {
    if (i <= 1) return i;
    ll &ret = dp[i];
    if (ret != -1) return ret;
    ret = go(i-1) + go(i-2);
    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(dp, dp+101, -1);

    cin >> n;
    cout << go(n);

    return 0;
}