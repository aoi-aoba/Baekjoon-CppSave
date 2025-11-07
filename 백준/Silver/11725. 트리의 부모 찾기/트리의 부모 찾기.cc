#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
vector<int> g[101010];
int ans[101010];
bool vs[101010];

int main(void) {
    fastio;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vs[1] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : g[cur]) {
            if (!vs[nxt]) {
                // 방문하지 않은 새로운 nxt는 cur의 자식
                vs[nxt] = true;
                ans[nxt] = cur;
                q.push(nxt);
            }
        }
    }

    for (int i = 2; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}