#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9;

int n, m, x;
int dist[1010], res[1010];
vector<pair<int, int>> graph[1010];

void dijkstra(int s) {
    fill(dist, dist + 1010, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [w, cur] = pq.top();
        pq.pop();
        for (auto [nxt, nxtw]: graph[cur]) {
            if (dist[nxt] > w + nxtw) {
                dist[nxt] = w + nxtw;
                pq.push({w + nxtw, nxt});
            }
        }
    }
}

int main(void) {
    fastio;
    cin >> n >> m >> x;
    
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        res[i] = dist[x];
    }
    
    dijkstra(x);

    int maxval = 0;
    for (int i = 1; i <= n; i++) {
        res[i] += dist[i];
        maxval = max(maxval, res[i]);
    }

    cout << maxval;

    return 0;
}