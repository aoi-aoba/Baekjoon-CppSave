#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, v;
vector<int> g[1010];
bool vsd[1010], vsb[1010];

void dfs(int cur) {
    cout << cur << ' ';
    vsd[cur] = true;
    for (int nxt: g[cur]) {
        if (!vsd[nxt]) {
            dfs(nxt);
        }
    }
}

void bfs(int sv) {
    queue<int> q;
    q.push(sv);
    vsb[sv] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int nxt: g[cur]) {
            if (!vsb[nxt]) {
                vsb[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

int main(void) {
    fastio;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());

    dfs(v);
    cout << '\n';
    bfs(v);

    return 0;
}