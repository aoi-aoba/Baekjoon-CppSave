#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int t, m, x;

int main(void) {
    fastio();

    cin >> t;
    while (t--) {
        cin >> m;
        priority_queue<int, vector<int>, greater<int>> minheap;
        priority_queue<int, vector<int>, less<int>> maxheap;
        vector<int> v;
        
        for (int i = 1; i <= m; i++) {
            cin >> x;
            if (maxheap.empty() || x <= maxheap.top()) maxheap.push(x);
            else minheap.push(x);

            if (maxheap.size() > minheap.size() + 1) {
                minheap.push(maxheap.top());
                maxheap.pop();
            } else if (minheap.size() > maxheap.size()) {
                maxheap.push(minheap.top());
                minheap.pop();
            }

            if (i % 2 == 1) v.push_back(maxheap.top());
        }
        
        cout << v.size() << '\n';
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
            if (i % 10 == 9) cout << '\n';
        }
        cout << '\n';
    }


    return 0;
}