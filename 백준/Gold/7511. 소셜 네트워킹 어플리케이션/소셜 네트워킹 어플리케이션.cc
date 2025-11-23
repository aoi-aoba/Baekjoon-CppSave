#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 1e6;
int parent[N+1];
int t, n, k, a, b, m;

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

void go() {
    cin >> n >> k;
    Init();

    while (k--) {
        cin >> a >> b;
        Union(a, b);
    }

    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << (Find(a) == Find(b) ? 1 : 0) << '\n';
    }
}

int main(void) {
    fastio();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Scenario " << i << ':' << '\n';
        go();
        cout << '\n';
    }
    return 0;
}