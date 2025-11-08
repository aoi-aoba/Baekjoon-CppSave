#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int a, b;

int go() {
    int cnt = 0;
    while (b > a) {
        if (b % 10 == 1) {
            b /= 10;
        } else if (b % 2 == 0) {
            b /= 2;
        } else break;
        cnt++;
    }
    if (b == a)
        return cnt + 1;
    else return -1;
}

int main(void) {
    fastio();
    cin >> a >> b;
    cout << go();
    return 0;
}