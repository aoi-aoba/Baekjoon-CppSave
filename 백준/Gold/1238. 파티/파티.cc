#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9;

int n, m, x;
int dist[1010], revdist[1010];
vector<pair<int, int>> graph[1010];
vector<pair<int, int>> revgr[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main(void) {
    fastio;
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        revgr[b].push_back({a, d});
    }

    fill(dist, dist + 1010, INF);
    fill(revdist, revdist + 1010, INF);

    dist[x] = revdist[x] = 0;
    pq.push({0, x});
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
    
    pq.push({0, x});
    while (!pq.empty()) {
        auto [w, cur] = pq.top();
        pq.pop();
        for (auto [nxt, nxtw]: revgr[cur]) {
            if (revdist[nxt] > w + nxtw) {
                revdist[nxt] = w + nxtw;
                pq.push({w + nxtw, nxt});
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF && revdist[i] != INF)
            res = max(dist[i] + revdist[i], res);
    }
    cout << res;

    return 0;
}