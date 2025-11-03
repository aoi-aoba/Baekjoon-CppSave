#include <bits/stdc++.h>
using namespace std;

int n, arr[1010101];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    fill(arr, arr+1010101, 0);
    for (int i = 1; i < n; i++) {
        if (arr[i + 1] > arr[i] + 1 || arr[i + 1] == 0)
            arr[i + 1] = arr[i] + 1;
        if (i * 2 < 1010101)
            if (arr[i * 2] > arr[i] + 1 || arr[i * 2] == 0)
                arr[i * 2] = arr[i] + 1;
        if (i * 3 < 1010101)
            if (arr[i * 3] > arr[i] + 1 || arr[i * 3] == 0)
                arr[i * 3] = arr[i] + 1;
    }
    
    cout << arr[n];
    return 0;
}