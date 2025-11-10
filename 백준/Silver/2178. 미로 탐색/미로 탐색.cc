#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
int mz[101][101];
int vst[101][101];

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    vst[1][1] = 1;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr < 1 || nr > n || nc < 1 || nc > m) continue;
            if (mz[nr][nc] ==  0 || vst[nr][nc] != 0) continue;
            q.push({nr, nc});
            vst[nr][nc] = vst[cr][cc] + 1;
        }
    }

    cout << vst[n][m] << '\n';
}

int main(void) {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            mz[i][j] = s[j-1] - '0';
        }
    }

    bfs();
    return 0;
}