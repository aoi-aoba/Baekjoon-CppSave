#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, str, stc;
char brd[601][601];
bool vst[601][601];

int bfs() {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({str, stc});
    vst[str][stc] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        if (brd[cr][cc] == 'P') cnt++;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (vst[nr][nc] || brd[nr][nc] == 'X') continue;
            q.push({nr, nc});
            vst[nr][nc] = true;
        }
    }

    return cnt;
}

int main(void) {
    fastio;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            brd[i][j] = s[j];
            if (s[j] == 'I') {
                str = i;
                stc = j;
            }
        }
    }

    int res = bfs();
    if (res == 0) cout << "TT" << '\n';
    else cout << res << '\n';

    return 0;
}