#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, packs[1010], dp[1010];

int go() {
    dp[1] = packs[1];
    dp[2] = min(packs[2], packs[1] * 2);
    for (int i = 3; i <= n; i++) {
        dp[i] = 1e9;
        for (int j = 0; j <= i; j++) {
            dp[i] = min(dp[i], packs[j] + dp[i-j]);
            // i장 카드 사려면 i 이하 j장의 카드팩 사고 남은 n-j장 싸게 사기
            // i = 5라면 (j, i-j)를 (1, 4)(2, 3)(3, 2)(4, 1)(5, 0) 체크
        }
    }
    return dp[n];
}

int main(void) {
    fastIO;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> packs[i];
    cout << go();
    return 0;
}