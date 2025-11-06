#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, v = 0;
vector<int> g[1010];
bool vs[1010];

void dfs(int cur) {
    vs[cur] = true;
    for (int nxt: g[cur]) {
        if (!vs[nxt]) {
            dfs(nxt);
        }
    }
}

int main(void) {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            v++;
            dfs(i);
        }
    }
    
    cout << v;

    return 0;
}