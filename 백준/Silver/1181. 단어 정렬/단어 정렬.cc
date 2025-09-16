#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

bool cmp(string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    else return a < b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    string prev;
    for (auto temp : v) {
        if (prev == temp) continue;
        else {
            cout << temp << '\n';
            prev = temp;
        }
    }
}