#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9+7;

int dist[101][101], N, M;

int main(void) {
    fastio;
    cin >> N >> M;
    fill(&dist[0][0], &dist[0][0] + 101 * 101, INF);

    for (int i = 1; i <= N; i++) dist[i][i] = 0;
    for (int i = 1; i <= M; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        dist[s][e] = min(dist[s][e], w);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}