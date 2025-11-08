#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, k;
int vs[100001];

int go() {
    deque<pair<int,int>> dq;
    dq.push_back({n, 0});
    vs[n] = 0;

    while (!dq.empty()) {
        auto cur = dq.front();
        dq.pop_front();

        int pos = cur.first;
        int time = cur.second;

        if (pos == k) return time;

        int c1 = pos * 2;
        int c2 = pos - 1;
        int c3 = pos + 1;

        if (c1 <= 100000 && (vs[c1] == -1 || vs[c1] > time)) {
            vs[c1] = time;
            dq.push_front({c1, time});
        }
        if (c2 >= 0 && (vs[c2] == -1 || vs[c2] > time + 1)) {
            vs[c2] = time + 1;
            dq.push_back({c2, time + 1});
        }
        if (c3 <= 100000 && (vs[c3] == -1 || vs[c3] > time + 1)) {
            vs[c3] = time + 1;
            dq.push_back({c3, time + 1});
        }
    }
    return -1;
}


int main(void) {
    fastio();
    cin >> n >> k;
    fill(vs, vs+100001, -1);
    cout << go();
    return 0;
}