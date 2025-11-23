#include <bits/stdc++.h>
using namespace std;

int parent[201];
int n, m;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 초기화
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // 인접 행렬 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) Union(i, j);
        }
    }

    // 여행 계획 입력
    vector<int> plan(m);
    for (int i = 0; i < m; i++)
        cin >> plan[i];

    // 첫 도시의 루트
    int root = Find(plan[0]);

    // 나머지 도시들이 같은 루트인지 확인
    for (int i = 1; i < m; i++) {
        if (Find(plan[i]) != root) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
