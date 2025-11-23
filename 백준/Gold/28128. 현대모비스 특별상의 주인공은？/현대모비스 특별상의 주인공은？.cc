#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    fastio();

    int N, M;
    cin >> N >> M;

    vector<vector<string>> board(N, vector<string>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    // 후보 이름 저장 (자동으로 정렬 & 중복 제거)
    set<string> candidates;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            // 1. 아래 인접 (i+1, j)
            if (i + 1 < N && board[i][j] == board[i+1][j])
                candidates.insert(board[i][j]);

            // 2. 오른쪽 인접 (i, j+1)
            if (j + 1 < M && board[i][j] == board[i][j+1])
                candidates.insert(board[i][j]);

            // 3. 아래로 한 칸 건너 (i+2, j)
            if (i + 2 < N && board[i][j] == board[i+2][j])
                candidates.insert(board[i][j]);

            // 4. 오른쪽으로 한 칸 건너 (i, j+2)
            if (j + 2 < M && board[i][j] == board[i][j+2])
                candidates.insert(board[i][j]);
        }
    }

    // 후보가 없으면 조작됨
    if (candidates.empty()) {
        cout << "MANIPULATED\n";
        return 0;
    }

    // 사전순으로 출력 (set이라 이미 정렬됨)
    for (auto &name : candidates)
        cout << name << '\n';

    return 0;
}
