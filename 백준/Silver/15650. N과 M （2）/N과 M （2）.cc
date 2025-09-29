#include <bits/stdc++.h>
using namespace std;

int n, m;
int chk[9];

void f(int k, int p) {
    if (k == m) {
        for (int i = 1; i <= n; i++)
            if (chk[i] == 1) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = p; i <= n; i++) {
        if (!chk[i]) {
            chk[i] = 1;
            f(k + 1, i);
            chk[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<int> v;
    f(0, 1);

    return 0;
}