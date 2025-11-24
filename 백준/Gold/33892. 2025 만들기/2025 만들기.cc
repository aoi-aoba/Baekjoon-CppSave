#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;

void go() {
    cout << "YES\n";
    if (n % 2 == 0) {
        while (n > 8) {
            cout << n << " - " << n - 1 << '\n';
            cout << "1 * 1\n";
            n -= 2;
        }
        cout << "8 - 4\n";
        cout << "7 + 2\n";
        cout << "1 + 4\n";
        cout << "3 + 6\n";
        cout << "5 * 9\n";
        cout << "5 * 9\n";
        cout << "45 * 45\n";
    } else {
        while (n > 7) {
            cout << n << " - " << n - 1 << '\n';
            cout << "1 * 1\n";
            n -= 2;
        }
        cout << "7 + 2\n";
        cout << "1 + 4\n";
        cout << "3 + 6\n";
        cout << "5 * 9\n";
        cout << "5 * 9\n";
        cout << "45 * 45\n";
    }
}

int main(void) {
    fastio;
    cin >> n;
    if (n <= 6) cout << "NO\n";
    else go();

    return 0;
}