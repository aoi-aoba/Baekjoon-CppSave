#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

struct Node {
    int index, dist;
};
int v, maxDist, maxNode;
bool vs[101010];
vector<Node> g[101010];

void dfs(int node, int dist) {
    if (vs[node]) return;
    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }
    vs[node] = true;
    for (int i = 0; i < g[node].size(); i++) {
        int nxtIdx = g[node][i].index;
        int nxtDist = g[node][i].dist;
        dfs(nxtIdx, nxtDist + dist);
    }
}

int main(void) {
    fastio();
    cin >> v;

    int fr, to, d;    
    for (int i = 1; i < v + 1; i++) {
        cin >> fr;
        while (true) {
            cin >> to;
            if (to == -1) break;
            cin >> d;
            g[fr].push_back({to, d});
            g[to].push_back({fr, d});
        }
    }

    dfs(1, 0);
    memset(vs, 0, sizeof(vs));
    maxDist = 0;
    
    dfs(maxNode, 0);
    cout << maxDist;
    return 0;
}