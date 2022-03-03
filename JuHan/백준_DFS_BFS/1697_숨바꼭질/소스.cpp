#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];
int n, k;

int bfs(int n, int k) {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	visited[n] = true;
	while (!q.empty()) {
		int line = q.front().first;
		int sec = q.front().second;
		q.pop();

		if (line == k) return sec;
		if (line + 1 < 100001 && !visited[line + 1]) {
			q.push(make_pair(line + 1, sec + 1));
			visited[line + 1] = true;
		}
		if (line - 1 >= 0 && !visited[line - 1]) {
			q.push(make_pair(line - 1, sec + 1));
			visited[line - 1] = true;
		}
		if (line * 2 < 100001 && !visited[line * 2]) {
			q.push(make_pair(line * 2, sec + 1));
			visited[line * 2] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	cout << bfs(n, k) << '\n';

	return 0;
}