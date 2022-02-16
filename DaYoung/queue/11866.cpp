#include<iostream>
#include<queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << "<";
	if (k == 1) {
		while (!q.empty()) {
			if (q.size() == 1) cout << q.front();
			else cout << q.front() << ", ";
			q.pop();
		}
		cout << ">";
	}
	else {
		while (!q.empty()) {
			for (int i = 0; i < k - 1; i++) {
				int f = q.front();
				q.pop();
				q.push(f);
			}
			if (q.size() == 1) cout << q.front();
			else cout << q.front() << ", ";
			q.pop();
		}
		cout << ">";
	}
	return 0;
}