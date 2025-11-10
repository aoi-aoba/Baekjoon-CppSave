#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 100000
using namespace std;

int n, m;
int par[MAX + 1];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    par[y] = x;
}

int main(void) {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;
    int ans = 0;
    bool flag = false;
    for (int i = 1; i <= m ; i++) {
        int a;
        cin >> a;
        a = find(a);
        if (a == 0) {
            flag = true;
        }
        if (!flag) {
            merge(a - 1, a);
            ans++;
        }
    }
    cout << ans;
    return 0;
}