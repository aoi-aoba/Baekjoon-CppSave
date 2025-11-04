#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 10007
using namespace std;

int n, res;
vector<int> v;

int go() {
    v.push_back(1);
    v.push_back(3);
    for (int i = 2; i < n; i++)
        v.push_back((v[i-2] * 2 + v[i-1]) % MOD);
        // 바로 이전 꺼에 세로줄 하나를 붙이거나
        // 그 이전꺼에 사각형 (가로줄 2개 혹은 정사각) 붙이기
    return v[n-1];
}

int main(void) {
    fastIO;
    cin >> n;
    cout << go() << ' ';

    return 0;
}