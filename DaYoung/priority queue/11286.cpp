#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				if (pq.top().second == 0) {
					cout << 0 - pq.top().first << "\n";
					pq.pop();
				}
				else {
					cout << pq.top().first << "\n";
					pq.pop();
				}
			}
		}
		else {
			if (x < 0) {
				pq.push(make_pair(abs(x), 0));
			}
			else pq.push(make_pair(x, 1));
		}
	}

	return 0;
}