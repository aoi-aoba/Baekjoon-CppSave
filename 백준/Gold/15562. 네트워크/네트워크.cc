#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, m, arr[1010101], res = 0;

int main(void) {
    fastio;
    cin >> n >> m;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a]++;
        arr[b]--;
    }

    for (int i = 0; i < n; i++)
        res += arr[i] > 0 ? arr[i] : 0;
    cout << res;
}