#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k;
int vst[101010];

int bfs() {
    queue<pair<int, int>> q;
    q.push({n, 0});
    vst[n] = 0;

    while (!q.empty()) {
        auto [cp, ct] = q.front();
        q.pop();
        int p1 = cp - 1, p2 = cp + 1, p3 = cp * 2;
        if (p1 >= 0 && vst[p1] == -1) {
            q.push({p1, ct + 1});
            vst[p1] = ct + 1;
        }
        if (p2 <= 100000 && vst[p2] == -1) {
            q.push({p2, ct + 1});
            vst[p2] = ct + 1;
        }
        if (p3 <= 100000 && vst[p3] == -1) {
            q.push({p3, ct + 1});
            vst[p3] = ct + 1;
        }
    }

    return vst[k];
}

int main(void) {
    fastio;
    cin >> n >> k;
    fill(vst, vst+101010, -1);
    cout << bfs();
    return 0;
}