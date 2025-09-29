#include <bits/stdc++.h>
using namespace std;

int e, s, m, a, b, c, cnt = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> e >> s >> m;
    a = 0, b = 0, c = 0;

    while (!(e == a && s == b && m == c)) {
        cnt++;
        a = (a == 15) ? 1 : a + 1;
        b = (b == 28) ? 1 : b + 1;
        c = (c == 19) ? 1 : c + 1;
    }

    cout << cnt;

    return 0;
}