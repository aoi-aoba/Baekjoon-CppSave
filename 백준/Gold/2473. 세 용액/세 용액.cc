#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> arr;
    int a, b, c;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    
    ll res = 3000000002;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            ll val = arr[i] + arr[left] + arr[right];
            if (abs(val) < res) {
                res = abs(val);
                a = arr[i];
                b = arr[left];
                c = arr[right];
            }
            if (val < 0) left++;
            else right--;
        }
    }

    cout << a << ' ' << b << ' ' << c;
    return 0;
}