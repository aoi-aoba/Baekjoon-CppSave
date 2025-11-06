#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool vi[51][51], infLoop = false;
int n, m, board[51][51], dp[51][51];
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
vector<pair<int, int>> v;

int go(int y, int x) {
    if (y < 1 || y > n || x < 1 || x > m || board[y][x] == -1)
        return 0;
    if (vi[y][x]) {
        infLoop = true;
        return 0;
    }
    if (dp[y][x]) return dp[y][x];

    vi[y][x] = true;
    int d = board[y][x], maxMove = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * d, nx = x + dx[i] * d;
        maxMove = max(maxMove, go(ny, nx));
        if (infLoop) return 0;
    }

    vi[y][x] = false;
    dp[y][x] = maxMove + 1;
    return dp[y][x];
}

int main(void) {
    fastio;
    cin >> n >> m;

    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (s[j-1] == 'H') board[i][j] = -1;
            else board[i][j] = s[j-1] - '0';
        }
    }

    int ans = go(1, 1);
    if (infLoop) cout << -1;
    else cout << ans;
    return 0;
}