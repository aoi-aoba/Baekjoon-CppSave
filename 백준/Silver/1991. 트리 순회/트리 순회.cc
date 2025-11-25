#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
array<char, 3> nodes[26];

void pretrev(array<char, 3> node) {
    cout << node[0];
    if (node[1] != '.')
        pretrev(nodes[node[1] - 'A']);
    if (node[2] != '.')
        pretrev(nodes[node[2] - 'A']);
}

void intrev(array<char, 3> node) {
    if (node[1] != '.')
        intrev(nodes[node[1] - 'A']);
    cout << node[0];
    if (node[2] != '.')
        intrev(nodes[node[2] - 'A']);
}

void posttrev(array<char, 3> node) {
    if (node[1] != '.')
        posttrev(nodes[node[1] - 'A']);
    if (node[2] != '.')
        posttrev(nodes[node[2] - 'A']);
    cout << node[0];
}

int main(void) {
    fastio;
    cin >> n;
    while (n--) {
        char a, b, c;
        cin >> a >> b >> c;
        nodes[a - 'A'] = {a, b, c};
    }
    pretrev(nodes[0]);
    cout << '\n';
    intrev(nodes[0]);
    cout << '\n';
    posttrev(nodes[0]);
    return 0;
}