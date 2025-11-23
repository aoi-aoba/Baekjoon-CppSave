#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 1e6;
int parent[N+1];
int n, m, a, b;

void Init() {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int Find(int x) {
    return parent[x] = parent[x] == x ? x : Find(parent[x]);
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u != v) parent[u] = v;
}


int main(void) {
    fastio();
    cin >> n >> m;
    Init();
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        int pa = Find(a);
        int pb = Find(b);

        if (pa == pb) {
            cout << i << '\n';
            return 0;
        } else {
            Union(a, b);
        }
    }

    cout << 0 << '\n';
    return 0;
}