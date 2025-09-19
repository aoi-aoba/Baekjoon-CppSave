#include <bits/stdc++.h>

using namespace std;


int n, m, res;
vector<pair<int, int>> v;
vector<vector<char>> arr;

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool inrange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void findFox(int r, int c) {
    for (int d = 0; d < 8; d++) {
        int nr1 = r + dr[d], nc1 = c + dc[d];
        if(!inrange(nr1, nc1)) continue;
        if(arr[nr1][nc1] != 'O') continue;

        int nr2 = nr1 + dr[d], nc2 = nc1 + dc[d];
        if(!inrange(nr2, nc2)) continue;
        if(arr[nr2][nc2] != 'X') continue;
        
        res++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
            if (s[j] == 'F')
                v.push_back({i, j});
        }
    }    

    for (pair<int, int> p : v) {
        findFox(p.first, p.second);
    }

    cout << res;
}