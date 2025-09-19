#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

vector<pair<int, int>> v;
vector<int> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 0; i < m; i++) {
        int g, x, y, score = 0;
        cin >> g >> x >> y;
        for (int j = 0; j < n; j++) {
            int a = v[j].first, b = v[j].second;
            if (x <= a && y <= b && a + b <= g)
                score++;
        }
        res.push_back(score);
    }

    for (int temp : res)
        cout << temp << '\n';
    return 0;
}