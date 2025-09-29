#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int mod = 1000;

struct mat {
    int n;
    vector<vector<int>> v;

    mat (int _n) {
        n = _n;
        v.resize(n, vector<int>(n));
    }
    
    mat operator *(const mat &x) {
        mat ret(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret.v[i][j] = (ret.v[i][j] + v[i][k] * x.v[k][j]) % mod;
                }
            }
        }

        return ret;
    }
};

mat I(0);

mat go(mat a, ll b) {
    if (b == 0)
        return I; // 배열의 0승은 항등원 I (단위대각행렬)
    
    if (b % 2 == 1)
        return a * go(a, b - 1);
    mat res = go(a, b / 2);
    return res * res;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll b;

    cin >> n >> b;

    mat a(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a.v[i][j];
        }
    }

    I = mat(n);
    for (int i = 0; i < n; i++)
        I.v[i][i] = 1; // 대각행렬 항등원

    mat res = go(a, b);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res.v[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}