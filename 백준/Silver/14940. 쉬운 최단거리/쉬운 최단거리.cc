#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, sr, sc;
int brd[1010][1010];
int vst[1010][1010];

void bfs() {
    queue<pair<int, int>> q;
    q.push({sr, sc});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if ((nr == sr && nc == sc) || brd[nr][nc] == 0 || vst[nr][nc] > 0) continue;
            q.push({nr, nc});
            vst[nr][nc] = vst[cr][cc] + 1;
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (brd[i][j] == 1 && vst[i][j] == 0) cout << -1 << ' ';
            else cout << vst[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> brd[i][j];
            if (brd[i][j] == 2) {
                sr = i;
                sc = j;
            }
        }
    }
    bfs();
    print();
    return 0;
}