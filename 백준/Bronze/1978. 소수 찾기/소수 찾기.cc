#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;
int N, cnt = 0, p[MAX];

void sieve() {
  fill(p, p + MAX, 1);

  p[1] = 0;
  for (int i = 2; i * i < MAX; i++) {
    if (!p[i]) continue;
    for (int j = i * i; j < MAX; j+=i) {
      p[j] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  sieve();
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (p[x]) cnt++;
  }

  cout << cnt;
}