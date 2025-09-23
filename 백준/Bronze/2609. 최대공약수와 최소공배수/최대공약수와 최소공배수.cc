#include <bits/stdc++.h>
using namespace std;


int euclidean(int a, int b) {
    if (b == 0) return a;
    return euclidean(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    int gcd = (n > m) ? euclidean(n, m) : euclidean(m, n);
    cout << gcd << '\n' << n * m / gcd;

    return 0;
}