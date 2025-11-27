#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int n, m;
int parent[1010101];
char a[1010][1010];

int Find(int x) {
    return parent[x] = (parent[x] == x ? x : Find(parent[x]));
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u != v) parent[u] = v;
}

void Init() {
    for (int i = 0; i < n * m; i++)
        parent[i] = i;
}

int main(void) {
    fastio;
    cin >> n >> m;

    Init();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = m*i + j;
            if (a[i][j] == 'D') Union(cur, m*(i+1) + j);
            if (a[i][j] == 'U') Union(cur, m*(i-1) + j);
            if (a[i][j] == 'R') Union(cur, m*i + (j+1));
            if (a[i][j] == 'L') Union(cur, m*i + (j-1));
        }
    }

    set<int> s;
    for (int i = 0; i < n * m; i++) {
        s.insert(Find(i));
    }

    cout << s.size();
    return 0;
}
