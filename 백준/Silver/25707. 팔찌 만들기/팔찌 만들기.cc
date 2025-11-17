#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, x, arr[1010];

int main(void) {
    fastio();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int sum = abs(arr[0] - arr[n - 1]);
    for (int i = 1; i < n; i++) {
        sum += abs(arr[i] - arr[i-1]);
    }

    cout << sum;
    return 0;
}