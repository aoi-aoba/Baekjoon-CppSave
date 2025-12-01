#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string inorder, post;
stack<char> st;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main(void) {
    fastio;
    cin >> inorder;

    for (char c : inorder) {
        if ('A' <= c && c <= 'Z') post += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        post += st.top();
        st.pop();
    }

    cout << post << '\n';
    return 0;
}