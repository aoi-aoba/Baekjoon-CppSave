#include <bits/stdc++.h>
using namespace std;

int t, m, n, x, y;

int euclidean(int a, int b) {
    if (b == 0) return a;
    else return euclidean(b, a % b);
}

int conv() {
    int lcm = m * n / ((m > n) ? euclidean(m, n) : euclidean(n, m));
    for (int i = x, j = y; i <= lcm, j <= lcm;) {
        if (i == j) return i;
        else if (i < j) i += m;
        else j += n;
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;
        cout << conv() << '\n';
    }

    return 0;
}