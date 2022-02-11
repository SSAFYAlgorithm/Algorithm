#include<iostream>
#include<deque>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	deque<int> dq;
	int n, m, x, cnt = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> x;
		int flag = 0;
		for (int j = 0; j <= dq.size() / 2; j++) {
			if (dq.front() == x) {
				dq.pop_front();
				flag = 1;
				break;
			}
			else {
				int f = dq.front();
				dq.pop_front();
				dq.push_back(f);
				cnt++;
			}
		}
		if (flag == 0) {
			for (int j = 0; j <= dq.size() / 2; j++) {
				int f = dq.back();
				dq.pop_back();
				dq.push_front(f);
				cnt--;
			}
			for (int j = 0; j <= dq.size() / 2; j++) {
				if (dq.front() == x) {
					dq.pop_front();
					flag = 1;
					break;
				}
				int f = dq.back();
				dq.pop_back();
				dq.push_front(f);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}