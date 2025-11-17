#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n;

void go(int n) {
    if (n == 1) {
        cout << "1";
    } else if (n == 3) {
        cout << "1 3 2";
    } else {
        cout << "4 2 3 1";
        for (int i = 5; i <= n; i++) {
            cout << ' ' << i;
        }
    }
}

int main(void) {
    fastio();

    cin >> n;
    if (n == 2) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    go(n);

}