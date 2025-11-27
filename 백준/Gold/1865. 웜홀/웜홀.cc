#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

const ll INF = 1e18;

ll dist[501], TC, N, M, W;
vector<array<int, 3>> graph;

bool bf(int s) {
    fill(dist, dist+501, INF);
    dist[s] = 0;
    for (int i = 0; i < N; i++) {
        for (auto [s, e, w]: graph) {
            if (dist[e] > dist[s] + w) {
                dist[e] = dist[s] + w;
                if (i == N - 1) return false;
            }
        }
    }
    return true;
}

int main(void) {
    fastio;
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        graph.clear();
        for (int i = 1; i <= M; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            graph.push_back({s, e, t});
            graph.push_back({e, s, t});
        }
        for (int i = 1; i <= W; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            graph.push_back({s, e, -t});
        }
        if (bf(N)) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}