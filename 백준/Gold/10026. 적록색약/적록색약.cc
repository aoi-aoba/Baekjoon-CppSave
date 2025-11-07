#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
int dr[4] = {0, 0, -1, 1}, dc[4] = {-1, 1, 0, 0};
bool nvs[101][101], rgvs[101][101];
char narr[101][101], rgarr[101][101];

void bfs(int t, int r, int c) {
    if (t == 0) { // 비색약
        queue<pair<int, int>> q;
        q.push({r, c});
        nvs[r][c] = true;

        while (!q.empty()) {
            auto[cr, cc] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i], nc = cc + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || nvs[nr][nc] || narr[nr][nc] != narr[cr][cc])
                    continue;
                nvs[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    } else { // 적녹색약
        queue<pair<int, int>> q;
        q.push({r, c});
        rgvs[r][c] = true;

        while (!q.empty()) {
            auto[cr, cc] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i], nc = cc + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || rgvs[nr][nc] || rgarr[nr][nc] != rgarr[cr][cc])
                    continue;
                rgvs[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main(void) {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            narr[i][j] = temp;
            if (temp == 'B') rgarr[i][j] = 'B';
            else rgarr[i][j] = 'T';
        }
    }

    int rn = 0, rrg = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!nvs[i][j]) {
                bfs(0, i, j);
                rn++;
            }
            if (!rgvs[i][j]) {
                bfs(1, i, j);
                rrg++;
            }
        }
    }

    cout << rn << ' ' << rrg;

    return 0;
}