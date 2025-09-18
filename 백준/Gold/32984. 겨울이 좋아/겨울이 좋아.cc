#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int right = -1;
    for (int i = 0; i < n; i++)
        right = max(right, (a[i] + b[i] - 1) / b[i]);
        // round
    int left = 1;

    while (left < right) {
        int mid = (left + right) / 2, ex = 0;
        bool flag = true;

        for (int i = 0; i < n; i++) {
            int fin = (a[i] + b[i] - 1) / b[i];
            if (fin > mid) {
                ex += fin - mid;
                if (ex > mid) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) right = mid;
        else left = mid + 1;
    }

    cout << left << '\n';

    return 0;
} 