#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, k = 1010;

int main(void) {
    fastio();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        k = min(k, r - l + 1);
    }

    int num = 1;
    for (int i = 0; i < n; i++) {
        cout << num++ << ' ';
        if (num > k) num = 1;
    }

    return 0;
}