#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, n, m, input;
    vector<ll> A, B, sumA, sumB;

    cin >> t >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        A.push_back(input);
    }

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            sumA.push_back(sum);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;
        B.push_back(input);
    }

    for (int i = 0; i < m; i++) {
        ll sum = 0;
        for (int j = i; j < m; j++) {
            sum += B[j];
            sumB.push_back(sum);
        }
    }
    
    sort(sumB.begin(), sumB.end());

    ll res = 0;
    for (int val : sumA) {
        ll value = t - val;
        int idx1 = lower_bound(sumB.begin(), sumB.end(), value) - sumB.begin();
        int idx2 = upper_bound(sumB.begin(), sumB.end(), value) - sumB.begin();
        res += (idx2 - idx1);
    }

    cout << res;

    return 0;
}