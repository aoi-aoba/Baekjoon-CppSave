#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll N, K;
vector<int> prime;

ll cnt() {
    ll res = 0;
    for (int p : prime) {
        ll tempCnt = K / p;
        while (tempCnt) {
            res += tempCnt;
            tempCnt /= p;
        }
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    prime.resize(N);
    for (int i = 0; i < N; i++)
      cin >> prime[i];
    cin >> K;

    cout << cnt();
}