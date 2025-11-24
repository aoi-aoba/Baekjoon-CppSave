#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef long long ll;

const ll INF = 1e18;

int n, m;
vector<tuple<int, int, int>> edges;
ll dist[505];

int main() {
    fastio;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    fill(dist, dist + 505, INF);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto& [a, b, c] : edges) {
            if (dist[a] != INF && dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
            }
        }
    }
    
    // check minus cycle
    for (auto& [a, b, c] : edges) {
        if (dist[a] != INF && dist[b] > dist[a] + c) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
}