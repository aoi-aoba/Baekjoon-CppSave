#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int l, s;
int dx[6] = {1, 2, 3, 4, 5, 6};
int brd[101];
bool vst[101];

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    vst[1] = true;

    while (!q.empty() && !vst[100]) {
        auto [x, d] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            if (nx >= 0 && nx < 101 && !vst[nx]) {
                if (brd[nx] == 0) {
                    q.push({nx, d+1});
                    vst[nx] = true;
                    brd[nx] = d + 1;
                } else {
                    q.push({brd[nx], d + 1});
                    vst[nx] = true;
                    brd[brd[nx]] = d + 1;
                }
            }
        }
    }

    cout << brd[100];
}

int main(void) {
    fastio;
    cin >> l >> s;
    for (int i = 0; i < l; i++) {
        int st, en;
        cin >> st >> en;
        brd[st] = en;
    }
    
    for (int i = 0; i < s; i++) {
        int st, en;
        cin >> st >> en;
        brd[st] = en;
    }
    bfs();
    return 0;
}