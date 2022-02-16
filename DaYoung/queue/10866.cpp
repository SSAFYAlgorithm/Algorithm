#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, k;
	string s;
	deque<int> dq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_front") {
			cin >> k;
			dq.push_front(k);
		}
		else if (s == "push_back") {
			cin >> k;
			dq.push_back(k);
		}
		else if (s == "pop_front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << "\n";
		}
		else if (s == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (s == "front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (s == "back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}
	return 0;
}