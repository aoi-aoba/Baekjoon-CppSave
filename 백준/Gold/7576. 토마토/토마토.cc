#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
int arr[1010][1010], dist[1010][1010];

int main(void) {
    fastio;
    cin >> m >> n;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            } else dist[i][j] = -1;
        }
    }

    int mv_r[4] = {0, 0, 1, -1};
    int mv_c[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto cur = q.front();
        int r = cur.first, c = cur.second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = r + mv_r[i], nc = c + mv_c[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m 
                || dist[nr][nc] != -1 || arr[nr][nc] == -1)
                continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0 && dist[i][j] == -1) {
                flag = true;
            } else ans = max(ans, dist[i][j]);
        }
    }

    if (flag) cout << -1;
    else cout << ans;
    return 0;
}