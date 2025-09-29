#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, x;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;    
        v.push_back(x);
    }

    int val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = v[i] + v[j] + v[k];
                if (sum <= m) val = max(sum, val);
            }
        }
    }

    cout << val;

    return 0;
}