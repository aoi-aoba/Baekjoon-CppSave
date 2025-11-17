#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    fastio;
    cin >> n >> k;
    while (n--) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }
    cout << pq.top();
    return 0;
}