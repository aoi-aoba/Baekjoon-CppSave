#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(10001, 0);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, minVal = 10001, maxVal = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
        minVal = min(x, minVal);
        maxVal = max(x, maxVal);
    }
    
    for (int i = minVal; i <= maxVal; i++) {
        if (v[i] == 0) continue;
        for (int j = 0; j < v[i]; j++)
            cout << i << '\n';
    }
}