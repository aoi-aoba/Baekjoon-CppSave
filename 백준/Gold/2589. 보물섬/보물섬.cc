#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int vs[51][51];
char a[51][51];

vector<pair<int, int>> points;

int go(pair<int, int> st) {
    auto [row, col] = st;
    queue<array<int, 3>> q;
    q.push({row, col, 0});

    fill(&vs[0][0], &vs[n][m], -1);
    vs[row][col] = 0;

    int res = 0;
    while (!q.empty()) {
        auto [r, c, t] = q.front();
        q.pop();
        res = max(res, t);
        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + r, nc = dc[i] + c;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;;
            if (vs[nr][nc] != -1 || a[nr][nc] == 'W') continue;
            vs[nr][nc] = t + 1;
            q.push({nr, nc, t+1});
        }
    }

    return res;
}

int main(void) {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'L')
                points.push_back({i, j});
        }
    }

    int res = 0;
    for (auto point: points) {
        res = max(go(point), res);
    }
    cout << res;

    return 0;
}