#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int n, s;
ll res = 0;
vector<int> A, B, arr(40);

void subsetA(int sum, int k) {
    if (k >= n / 2) return;
    sum += arr[k];
    if (sum == s) res++;
    A.push_back(sum);
    subsetA(sum - arr[k], k + 1);
    subsetA(sum, k + 1);
}

void subsetB(int sum, int k) {
    if (k >= n) return;
    sum += arr[k];
    if (sum == s) res++;
    B.push_back(sum);
    subsetB(sum - arr[k], k + 1);
    subsetB(sum, k + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    subsetA(0, 0);
    subsetB(0, n / 2);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
        int find = s - A[i];
        int low = lower_bound(B.begin(), B.end(), find) - B.begin();
        int high = upper_bound(B.begin(), B.end(), find) - B.begin();
        res += (high - low);
    }

    cout << res << '\n';
    return 0;
}
