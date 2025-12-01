#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

struct djs {
    int n;
    vector<int> par, sz;

    void init(int _n) {
        n = _n;
        par.resize(n+1);
        sz.resize(n+1);
        for (int i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
    }

    int Find(int x) {
        if (par[x] == x) return x;
        return par[x] = Find(par[x]);
    }

    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a == b) return;
        par[a] = b;
        sz[b] += sz[a];
    }
};

int n;
pair<ll, ll> arr[100001];
vector<int> adj[100001];
bool check[100001];

int main(void) {
    fastio();
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i].first, arr[i].second = i;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    djs djs;
    djs.init(n);

    sort(arr+1, arr+1+n, greater<>());
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        auto [w, idx] = arr[i];
        check[idx] = 1;

        for (int a : adj[idx])
            if (check[a])
                djs.Union(a, idx);

        ans = max(ans, w * djs.sz[djs.Find(idx)]);
    }

    cout << ans;
    return 0;
}
