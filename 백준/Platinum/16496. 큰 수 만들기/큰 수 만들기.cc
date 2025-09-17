#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, temp;
    bool isZero = true;
    vector<string> num;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp != 0) isZero = false;
        num.push_back(to_string(temp));
    }

    if (isZero) cout << 0;
    else {
        sort(num.begin(), num.end(), cmp);
        for (int i = 0; i < n; i++)
            cout << num[i];
    }

    return 0;
}

/*
								    3	30	34	5	9
93>39, 930>309, 934>349, 95>59		9	3	30	34	5
53>35, 530>305, 534>345		    	9	5	3	30	34
3430>3034, 343>334		    		9	5	34	3	30
330>303	    						9	5	34	3	30
    								9534330

*/