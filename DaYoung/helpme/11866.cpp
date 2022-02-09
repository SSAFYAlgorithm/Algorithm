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
			cout << q.front() << ", ";
			q.pop();
		}
		cout << "\b\b>";
	}
	else {
		while (!q.empty()) {
			for (int i = 0; i < k - 1; i++) {
				int f = q.front();
				q.pop();
				q.push(f);
			}
			cout << q.front() << ", ";
			q.pop();
		}
		cout << "\b\b>";
	}
	return 0;
}