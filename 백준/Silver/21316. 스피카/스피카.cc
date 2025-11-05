#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> v[13], v2[13];
int a, b = 0;

int main() {
    for (int i = 0; i < 12; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i < 13; i++) {
        if (v[i].size() == 3) {
            for (int j = 0; j < 3; j++) v2[i].push_back(v[v[i][j]].size());
            sort(v2[i].begin(), v2[i].end());
            if (v2[i][0] == 1 && v2[i][1] == 2 && v2[i][2] == 3)
                cout << i;
        }
    }

    return 0;
}