#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int M, N;
int p[MAX];
vector<int> prime;

void sieve(int s, int e) {
  fill(p, p+MAX, 1);
  p[1] = 0;

  for (int i=2; i*i<MAX; i++) {
    if (p[i] == 0) continue;
    for (int j=i*i; j<MAX; j+=i) {
      p[j] = 0;
    }
  }

  for (int i=s; i<=e; i++)
    if (p[i]) cout << i << '\n';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> M >> N;
  sieve(M, N);
  
  return 0;
}