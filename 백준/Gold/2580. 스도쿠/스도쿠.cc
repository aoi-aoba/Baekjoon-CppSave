#include <bits/stdc++.h>

using namespace std;

int x, cnt;
bool fillAll = false;
const int SIZE = 9;
vector<pair<int, int>> poss;
vector<vector<int>> board;

bool ok(int r, int c, int tar) {
    for (int i = 0; i < SIZE; i++)
        if (board[r][i] == tar || board[i][c] == tar) return false;
    int sr = (r / 3) * 3, sc = (c / 3) * 3;
    for (int i = sr; i < sr + 3; i++)
        for (int j = sc; j < sc + 3; j++)
            if(board[i][j] == tar) return false;
    return true;
}

void go(int d) {
    if (d == cnt) {
        fillAll = true;
        return;
    }

    auto cellPos = poss[d];
    int r = cellPos.first, c = cellPos.second;
    for (int i = 1; i <= SIZE; i++) {
        if (ok(r, c, i)) {
            board[r][c] = i;
            go(d + 1);
            if (fillAll) return;
            board[r][c] = 0;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    board.resize(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> x;
            board[i][j] = x;
            if (x == 0) {
                poss.push_back({i, j});
                cnt++;
            }
        }
    }
    
    go(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}