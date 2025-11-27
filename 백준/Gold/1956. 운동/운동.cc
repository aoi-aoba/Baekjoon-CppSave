#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9;

int dist[404][404], V, E;

int main(void) {
    fastio;
    cin >> V >> E;
    fill(&dist[0][0], &dist[0][0] + 404 * 404, INF);

    for (int i = 1; i <= E; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        dist[s][e] = min(dist[s][e], w);
    }

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


    int ans = INF * 2;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (dist[i][j] == INF || dist[j][i] == INF) continue;
            if (i == j) ans = min(ans, dist[i][j]);
            else ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }

    if (ans == INF * 2) cout << -1;
    else cout << ans;

    return 0;
}