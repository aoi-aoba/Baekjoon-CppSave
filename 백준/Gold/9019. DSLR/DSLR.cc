#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int t, a, b;
bool vst[10101];

void bfs(int a, int b) {
    queue<pair<int, string>> q;
    q.push({a, ""});
    vst[a] = true;

    while (!q.empty()) {
        auto cur = q.front();
        int n = cur.first;
        string cm = cur.second;
        q.pop();
        
        if (n == b) {
            cout << cm << '\n';
            break;
        }
        
        int d = (n * 2) % 10000, s = (n > 0) ? n - 1 : 9999;
        int l = (int)(n / 1000) + (n % 1000) * 10;
        int r = (n % 10) * 1000 + (int)(n / 10);

        if (!vst[d]) {
            vst[d] = true;
            q.push({d, cm + "D"});
        }
        if (!vst[s]) {
            vst[s] = true;
            q.push({s, cm + "S"});
        }
        if (!vst[l]) {
            vst[l] = true;
            q.push({l, cm + "L"});
        }
        if (!vst[r]) {
            vst[r] = true;
            q.push({r, cm + "R"});
        }
    }
}

int main(void) {
    fastio();
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        fill(vst, vst + 10101, false);
        bfs(a, b);
    }

    return 0;
}