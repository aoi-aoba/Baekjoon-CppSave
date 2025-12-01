#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;

int main(void) {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        stack<int> st;
        bool isVPS = true;
        for (auto c : str) {
            if (c == '(') st.push(1);
            else if (!st.empty()) st.pop();
            else {
                isVPS = false;
                break;
            }
        }
        if (st.empty() && isVPS) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}