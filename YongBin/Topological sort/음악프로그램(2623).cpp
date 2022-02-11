#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int degree[1001];
vector<int> result;
vector<int> node[1001];
queue<int> q;

int main() {
	int n, m, num, a;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		vector<int> temp;
		for (int j = 0; j < num; j++) {
			cin >> a;
			temp.push_back(a);
		}
		for (int k = 0; k < temp.size(); k++) {
			for (int j = k + 1; j < temp.size(); j++) {
				node[temp[k]].push_back(temp[j]);
				degree[temp[j]]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		result.push_back(x);

		for (int i = 0; i < node[x].size(); i++) {
			int nx = node[x][i];
			degree[nx]--;
			
			if (degree[nx] == 0)
				q.push(nx);
		}
	}

	for (int i = 0; i < n; i++) {
		if (degree[i] > 0) {
			cout << 0;
			return 0;
		}
	}

	for (auto it : result) {
		cout << it << "\n";
	}
	return 0;
}