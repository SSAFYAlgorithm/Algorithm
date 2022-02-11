#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int degree[32001];
vector<int> node[32001];
vector<int> result;
queue<int> q;


int main() {
	int n, m, a, b;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		node[a].push_back(b);
		degree[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			result.push_back(i);
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		 
		for (int i = 0; i < node[x].size(); i++) {
			int nx = node[x][i];
			degree[nx]--;
			if (degree[nx] == 0) {
				q.push(nx);
				result.push_back(nx);
			}
				
		}
	}

	for (auto it : result) {
		cout << it << " ";
	}

	return 0;

}