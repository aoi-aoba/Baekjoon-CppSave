#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int r, c, res = 0;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
char arr[22][22];
bool vsa[26];

void move(int dep, int pr, int pc) {
    if (vsa[arr[pr][pc] - 'A']) return;
    res = max(res, dep);
    
    vsa[arr[pr][pc] - 'A'] = true;
    for (int i = 0; i < 4; i++) {
        int nr = pr + dr[i], nc = pc + dc[i];
        if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
        if (vsa[arr[nr][nc] - 'A']) continue;
        move(dep + 1, nr, nc);
    }
    vsa[arr[pr][pc] - 'A'] = false;
}

int main(void) {
    fastio;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
            arr[i][j] = s[j];
    }

    move(1, 0, 0);
    cout << res;
    return 0;
}