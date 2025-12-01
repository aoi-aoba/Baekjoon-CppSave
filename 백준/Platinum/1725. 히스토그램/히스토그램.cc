#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, temp, ans = 0;
stack<pair<int, int>> st;

int main(void) {
    fastio;
    cin >> n;
    st.push({-1, -1});

    for (int i = 0; i < n; i++) {
        cin >> temp;
        while (!st.empty()) {
            auto [idx, h] = st.top();
            if (h < temp) {
                break;
            }
            st.pop();
            auto [idx2, h2] = st.top();
            ans = max(ans, (i-idx2-1)*h);
        }
        st.push({i, temp});
    }
    
    while (st.size() > 1) {
        auto [idx, h] = st.top();
        st.pop();
        auto [idx2, h2] = st.top();
        ans = max(ans, (n-idx2-1)*h);
    }
    
    cout << ans;
    return 0;
}