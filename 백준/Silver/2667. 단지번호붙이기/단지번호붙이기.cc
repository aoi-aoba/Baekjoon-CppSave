#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
int ar[30][30];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
bool vs[30][30];
vector<int> res;

int bfs(int r, int c) {
    int area = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    vs[r][c] = true;

    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || vs[nr][nc] || !ar[nr][nc])
                continue;
            area++;
            vs[nr][nc] = true;
            q.push({nr, nc});
        }    
    }

    return area;
}

int main(void) {
    fastio;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            ar[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vs[i][j] && ar[i][j])
                res.push_back(bfs(i, j));
        }
    }

    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for (int cur : res)
        cout << cur << '\n';
    return 0;
}