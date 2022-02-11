#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<int> q;
	int command_cnt;
	cin >> command_cnt;

	int front_data;

	for (int i = 0; i < command_cnt; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (command == "pop") {
			if (q.size() == 0) cout << -1 << '\n';
			else {
				front_data = q.front();
				q.pop();
				cout << front_data << '\n';
			}
		}
		else if (command == "size") {
			cout << q.size() << '\n';
		}
		else if (command == "empty") {
			cout << q.empty() << '\n';
		}
		else if (command == "front") {
			if (q.size() == 0)cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (command == "back") {
			if (q.size() == 0)cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
	return 0;
}