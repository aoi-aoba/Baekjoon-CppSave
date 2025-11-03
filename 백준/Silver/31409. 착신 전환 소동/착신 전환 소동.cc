#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, res;
vector<int> v;

int main(void) {
    fastIO;
    cin >> n;

    v.push_back(0);
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if (i == temp) {
            res++;
            v.push_back(i + 1 > n ? (i + 1) % n : i + 1);
        } else v.push_back(temp);
    }

    cout << res << '\n';
    for (int i = 1; i <= n; i++)
        cout << v[i] << ' ';
    return 0;
}