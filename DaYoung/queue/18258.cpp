#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, k;
	string s;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> k;
			q.push(k);
		}
		else if (s == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			cout << q.empty() << "\n";
		}
		else if (s == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (s == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
	return 0;
}