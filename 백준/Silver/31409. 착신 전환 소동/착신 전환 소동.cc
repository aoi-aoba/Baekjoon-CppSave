#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, a[101010], res = 0;

int main(void) {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == i) {
            res++;
            if (i == n) a[i] = 1;
            else a[i] = n;
        }
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
}