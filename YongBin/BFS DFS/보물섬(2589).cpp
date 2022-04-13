#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, answer;
char map[51][51];
int visited[51][51];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int bfs(int x, int y) {
	int ret = 0;
	queue<pair<int, int>> q;

	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();

		if (ret < visited[sx][sy])
			ret = visited[sx][sy];

		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && map[nx][ny] == 'L') {
				q.push({ nx,ny });
				visited[nx][ny] = visited[sx][sy] + 1;
			}
		}
	}
	return ret - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp; 
		cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				memset(visited, 0, sizeof(visited));
				answer = max(bfs(i, j), answer);
			}
		}
	}
	cout << answer;
	return 0;
}