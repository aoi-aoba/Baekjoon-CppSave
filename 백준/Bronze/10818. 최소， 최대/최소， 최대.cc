#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t, minVal = 1000000, maxVal = -1000000;
    cin >> n;
    while (n--) {
        cin >> t;
        minVal = min(minVal, t);
        maxVal = max(maxVal, t);
    }
	cout << minVal << " " << maxVal << "\n";

    return 0;
}