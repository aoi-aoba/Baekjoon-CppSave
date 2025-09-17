#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        int a, d, x;
        cin >> a >> d >> x;
        
        ll left = 1, right = 1000000, temp = 0;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll val = 1 + a * (mid - 1) + d * (mid - 1) * (mid - 2) / 2;

            if (val <= x) {
                left = mid + 1;
                temp = val;
            } else right = mid - 1;
        }
        
        cout << right << ' ' << x - temp + 1 << '\n';
    }

    return 0;
}