#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec[20001];
int visited[20001] = { 0 };
int v, e, a, b;

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	int temp = 1; //1 or 2

	visited[idx] = temp;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (visited[x] == 1)
			temp = 2;
		else if (visited[x] == 2)
			temp = 1;

		for (int i = 0; i < vec[x].size(); i++) {
			int nx = vec[x][i];
			if (visited[nx] == 0) {
				visited[nx] = temp;
				q.push(nx);
			}
		}
	}
}

int check() {
	for (int i = 0; i <= v; i++) {
		for (int j = 0; j < vec[i].size(); j++) 
			if (visited[i] == visited[vec[i][j]])
				return 0;
	}
	return 1;
}

int main() {
	int k;
	cin >> k;
	for (int t = 0; t < k; t++) {
		cin >> v >> e;

		for (int i = 1; i <= v; i++) {
			vec[i].clear();
		}

		for (int i = 1; i <= v; i++) {
			visited[i] = 0;
		}

		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (visited[i] == 0)
				bfs(i);
		}


		if (check() == 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}