#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, x;

int main(void) {
    fastio;

    priority_queue<int, vector<int>, greater<int>> pq_plus;
    // 양수는 최소 힙
    priority_queue<int, vector<int>, less<int>> pq_minus;
    // 음수는 최대 힙

    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (pq_plus.empty() && pq_minus.empty())
                cout << 0 << '\n';
            else if (pq_plus.empty()) {
                cout << pq_minus.top() << '\n';
                pq_minus.pop();
            } else if (pq_minus.empty()) {
                cout << pq_plus.top() << '\n';
                pq_plus.pop();
            } else {
                if (pq_minus.top() * (-1) <= pq_plus.top()) {
                    cout << pq_minus.top() << '\n';
                    pq_minus.pop();
                } else {
                    cout << pq_plus.top() << '\n';
                    pq_plus.pop();
                }
            }
        } else {
            if (x > 0) pq_plus.push(x);
            else pq_minus.push(x);
        }
    }

    return 0;
}