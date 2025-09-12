#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[201] = {}, n, t;
	cin >> n;
    while (n--) {
        cin >> t;
        arr[t + 100]++;
    }

    cin >> t;
	cout << arr[t + 100] << "\n";

    return 0;
}