#include <bits/stdc++.h>
using namespace std;

string a, b;
int al, bl, dp[1010][1010];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;
    al = a.size(), bl = b.size();
    a = ' '+ a, b = ' ' + b;

    for (int i = 1; i <= al; i++) {
        for (int j = 1; j <= bl; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    
    cout << dp[al][bl] << '\n';
    // cout << go(al, bl) << '\n';

    string res = "";
    int i = al, j = bl;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            res += a[i];
            i--, j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(res.begin(), res.end());
    cout << res << '\n';

    return 0;
}