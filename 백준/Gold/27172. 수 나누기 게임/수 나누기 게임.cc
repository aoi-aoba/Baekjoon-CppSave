#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010101;
int N, maxVal = 0;
vector<int> card, init, sorted;

void fun() {
    for (int temp : sorted) {
        for (int i = temp * 2; i <= maxVal; i += temp) {
            if (card[i] != -MAX) {
                card[i]--;
                card[temp]++;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        init.push_back(x);
        sorted.push_back(x);
    }

    sort(sorted.begin(), sorted.end());
    maxVal = sorted[sorted.size() - 1];
    card.resize(maxVal + 1, -MAX);
    for (int temp : init) card[temp] = 0;

    fun();
    for (int temp : init) cout << card[temp] << ' ';
    cout << '\n';
}