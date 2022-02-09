#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, k, a, b, w;
		int time[1001] = { 0 };
		int resultTime[1001] = { 0 };
		int degree[1001] = { 0 };
		vector<int> node[1001];
		queue<int> q;

		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}

		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			node[a].push_back(b);
			degree[b]++;
		}

		cin >> w;

		for (int i = 1; i <= n; i++) {
			if (degree[i] == 0) {
				q.push(i);
				resultTime[i] = time[i];
			}
		}

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < node[x].size(); i++) {
				int nx = node[x][i];
				resultTime[nx] = max(resultTime[nx], resultTime[x] + time[nx]);
				degree[nx]--;

				if (degree[nx] == 0)
					q.push(nx);
			}
		}

		cout << resultTime[w] << "\n";
	}
	return 0;
}