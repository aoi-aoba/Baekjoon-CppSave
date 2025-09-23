#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010101;
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

  sieve();

  while (true) {
    int x;
    cin >> x;
    if (x == 0) break;
    else {
      for (int i = 2; i <= x/2; i++) {
        if (p[i] && p[x-i]) {
          cout << x << " = " << i << " + " << x-i << "\n";
          break;
        }
      }
    }
  }
}