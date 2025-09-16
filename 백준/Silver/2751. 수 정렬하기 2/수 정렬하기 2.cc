#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    
    for (int temp : v)
        cout << temp << '\n';
}