#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 200000;
int parent[N+1];
int sz[N+1];
int t, f;
string a, b;

void Init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int x) {
    return parent[x] = (parent[x] == x ? x : Find(parent[x]));
}

int Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u != v) {
        parent[u] = v;
        sz[v] += sz[u];
    }
    return sz[v];
}

int main(void) {
    fastio();
    cin >> t;

    while (t--) {
        cin >> f;
        map<string, int> mp;
        int idx = 0;

        Init(2 * f);

        for (int i = 0; i < f; i++) {
            cin >> a >> b;

            if (!mp.count(a)) mp[a] = ++idx;
            if (!mp.count(b)) mp[b] = ++idx;

            int x = mp[a], y = mp[b];
            cout << Union(x, y) << '\n';
        }
    }
    return 0;
}
