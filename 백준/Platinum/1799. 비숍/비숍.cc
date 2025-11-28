#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pos pair<int, int>
using namespace std;

int n;
int board[10][10];
bool d1[20], d2[20]; // rdown, rup
vector<pos> sda, sdb;

int go(vector<pos>& v, int idx) {
    if (idx == v.size()) return 0;
    auto [r, c] = v[idx];
    int ret = 0;

    if (!d1[r+c] && !d2[r-c+9]) {
        d1[r+c] = d2[r-c+9] = true;
        ret = max(ret, 1 + go(v, idx+1));
        d1[r+c] = d2[r-c+9] = false;
    }

    ret = max(ret, go(v, idx+1)); // go through
    return ret;
}

int main(void) {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                if ((i + j) % 2 == 0) sda.push_back({i, j});
                else sdb.push_back({i, j});
            }
        }
    }

    cout << go(sda, 0) + go(sdb, 0);
    return 0;
}