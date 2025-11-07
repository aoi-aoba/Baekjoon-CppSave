#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, t;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int main(void) {
    fastio;
    cin >> t;

    while (t--) {
        int m, n, k, res = 0;
        int ar[50][50] = {};
        bool vs[50][50] = {};

        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            ar[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vs[i][j] == 0 && ar[i][j] == 1) {
                    res++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vs[i][j] = true;

                    while (!q.empty()) {
                        auto [cr, cc] = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int nr = cr + dr[i], nc = cc + dc[i];
                            if (nr < 0 || nr >= n || nc < 0 || nc >= m || vs[nr][nc] || !ar[nr][nc])
                                continue;
                            vs[nr][nc] = true;
                            q.push({nr, nc});
                        }    
                    }
                } else continue;
            }
        }
        
        cout << res << '\n';
    }
    return 0;
}