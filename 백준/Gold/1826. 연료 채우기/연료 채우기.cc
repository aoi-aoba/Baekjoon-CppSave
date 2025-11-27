#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, a, b, l, p, dist, cnt = 0;
pair<int, int> arr[10101];
priority_queue<int, vector<int>, less<>> pq;

int main(void) {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr+n);

    cin >> l >> p;
    dist = p;
    for (int i = 0; i < n; i++) {
        if (arr[i].first <= dist)
            pq.push(arr[i].second);
        else {
            while (!pq.empty() && dist < arr[i].first) {
                dist += pq.top();
                pq.pop();
                cnt++;
            }
            if (dist < arr[i].first) {
                cout << -1;
                return 0;
            }
            pq.push(arr[i].second);
        }
    }
    
    while (!pq.empty() && dist < l) {
        dist += pq.top();
        pq.pop();
        cnt++;
    }

    if (dist >= l) cout << cnt;
    else cout << -1;
    return 0;
}