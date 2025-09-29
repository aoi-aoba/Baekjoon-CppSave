#include <iostream>
#include <string>
using namespace std;

int n, m, c;
bool broken[10];

bool ok(string nowCh, int size) {
	for (int i = 0; i < size; ++i) {
		int num = nowCh[i] - '0';
		if (broken[num])
			return false;
	}
	return true;
}

int cntPush(int tar) {
	int push = 1000000;
	for (int cur = 0; cur <= 1000000; ++cur) {
		string curCh = to_string(cur);
		int size = curCh.size();
		if (!ok(curCh, size))
			continue;
		push = min(push, abs(tar - cur) + size);
	}
	return push;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int btn;
		cin >> btn;
		broken[btn] = true;
	}

	cout << min(abs(n - 100), cntPush(n));
}