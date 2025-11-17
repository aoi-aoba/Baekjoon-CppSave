#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(void) {
    fastio;

    int n = 0, a = 1;
    cin >> n;

    while (n--) {
        cout << a << " ";
        a += 2;
    }

    return 0;
}