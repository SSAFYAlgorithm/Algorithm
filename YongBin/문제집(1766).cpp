#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int degree[32001];
vector<int> node[32001];
vector<int> result;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	int n, m, a, b;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		degree[b]++;
		node[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int x = q.top();
		q.pop();
		result.push_back(x);

		for (int i = 0; i < node[x].size(); i++) {
			int nx = node[x][i];
			degree[nx]--;

			if (degree[nx] == 0)
				q.push(nx);
		}
	}

	for (auto it : result)
		cout << it << " ";

	return 0;
}