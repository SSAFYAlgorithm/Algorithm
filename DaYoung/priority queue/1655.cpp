#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<int> sq;
	priority_queue<int, vector<int>, greater<int>> lq;

	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (sq.empty()) sq.push(x);

		else if (sq.size() == lq.size()) {
			if (lq.top() >= x) sq.push(x);
			else {
				sq.push(lq.top());
				lq.pop();
				lq.push(x);
			}
		}

		else {
			if (sq.top() > x) {
				lq.push(sq.top());
				sq.pop();
				sq.push(x);
			}
			else lq.push(x);
		}
		cout << sq.top() << "\n";
	}

	return 0;
}