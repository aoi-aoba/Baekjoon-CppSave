#include <bits/stdc++.h>

using namespace std;

int n;

void move(int start, int dest) {
    cout << start << " " << dest << "\n";
}

void hanoi(int num, int start, int via, int dest) {
    if (num == 1)
        move(start, dest);
    else {
        hanoi(num - 1, start, dest, via);
        move(start, dest);
        hanoi(num - 1, via, start, dest);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << (int)(pow(2, n) - 1) << "\n";

    hanoi(n, 1, 2, 3);

    return 0;
}