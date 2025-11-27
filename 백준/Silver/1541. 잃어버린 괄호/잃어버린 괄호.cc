#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int res;
string s, n;
bool isMin = false;

int main() {
    fastio;
    cin >> s;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || i == s.size()) {
            if (isMin) {
                res -= stoi(n);
                n = "";
            } else {
                res += stoi(n);
                n = "";
            }
        } else n += s[i];
        if (s[i] == '-') isMin = true;
    }
    
    cout << res;
}
