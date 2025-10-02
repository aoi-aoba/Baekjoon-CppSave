#include <bits/stdc++.h>

using namespace std;

int l, c;
vector<char> v, now;
bool visited[15];

void go(int d, int prev) {
    if (d == l) {
        int cnt = 0;
        for (char ch : now)
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                cnt++;
        if (cnt >= 1 && d - cnt >= 2) {
            for (char ch : now)
                cout << ch;
            cout << "\n";
        }
        return;
    }
    for (int i = prev; i < c; i++) {
        if (!visited[i]) {
            visited[i] = true;
            now.push_back(v[i]);
            go(d + 1, i);
            now.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char ch;
        cin >> ch;
        v.push_back(ch);
    }

    sort(v.begin(), v.end());
    go(0, 0);

    return 0;
}