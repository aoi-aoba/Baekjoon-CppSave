#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int INF = 1e9 + 7;
using namespace std;

int m, n, s, e, dist[1001];
vector<pair<int, int>> adj[1001];

int main(void) {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    for (int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    cin >> s >> e;
    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (dist[cur] < d) continue;

        for (auto[nxt, w]: adj[cur]) {
            int nd = d + w;
            if (dist[nxt] > nd) {
                dist[nxt] = nd;
                pq.push({nd, nxt});
            }
        }
    }

    cout << dist[e];

    return 0;
}