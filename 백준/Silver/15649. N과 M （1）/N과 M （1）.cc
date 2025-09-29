#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> chk;

void f(int k, vector<int> v) {
    if (k == m) {
        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!chk[i]) {
            chk[i] = 1;
            v.push_back(i);
            f(k + 1, v);
            v.pop_back();
            chk[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    chk.resize(n + 1, 0);
    vector<int> v;
    f(0, v);

    return 0;
}