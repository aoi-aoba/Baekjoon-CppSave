#include <bits/stdc++.h>
using namespace std;

int n, m;

int getSum(int x) {
    int sum = x;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    bool ok = false;

    for (int i = 1; i < n; i++) {
        if (getSum(i) == n) {
            cout << i;
            ok = true;
            break;
        }
    }

    if(!ok) cout << '0';

    return 0;
}