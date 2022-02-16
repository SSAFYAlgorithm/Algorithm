#include<iostream>
#include<queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int c, n, m, p;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> m;
		int ans = 1;
		int idx = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < n; j++) {
			cin >> p;
			q.push(make_pair(p,idx++));
			pq.push(p);
		}
		while (1) {
			if (pq.top() == q.front().first) {
				if (q.front().second == m) {
					cout << ans << "\n";
					break;
				}
				pq.pop();
				q.pop();
				ans++;
			}
			else {
				pair<int, int> pp = q.front();
				q.pop();
				q.push(pp);
			}
		}
	}
	return 0;
}