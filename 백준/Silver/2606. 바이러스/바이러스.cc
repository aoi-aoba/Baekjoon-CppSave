#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m;
vector<int> adj[101];

bool vst[101];
int dfs(int cur) {
    vst[cur] = 1;
    int ret = 1;
    for (int nxt: adj[cur]) {
        if (!vst[nxt]) {
            ret += dfs(nxt);
        }
    }
    return ret;
}

int main(void) {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(1) - 1;
    return 0;
}