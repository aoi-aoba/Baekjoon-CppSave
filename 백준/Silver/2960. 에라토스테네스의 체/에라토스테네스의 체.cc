#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> removed;

void sieve() {
    vector<bool> isPrime(N + 1, true);

    for (int i = 2; i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i; j <= N; j += i) {
            if (isPrime[j]) {
                isPrime[j] = false;
                removed.push_back(j);
                if (removed.size() == K) return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    sieve();
    cout << removed[K - 1] << "\n";
}
