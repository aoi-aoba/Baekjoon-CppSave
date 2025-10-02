#include <bits/stdc++.h>

using namespace std;

int n, s, x, res = 0;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int set = (1 << n) - 1;
    for (int subset = set; subset > 0; subset = (subset - 1) & set) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if ((subset & (1 << i)) == (1 << i))
                sum += v[i];
        if (sum == s)
            res++;
    }

    cout << res;
    return 0;
}