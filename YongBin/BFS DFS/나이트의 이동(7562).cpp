#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,2,2,1,-1,-2,-2 };
int dy[] = { -2,-2,1,-1,2,2,1,-1 };

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m,x,y,rx,ry;
		queue < pair<pair<int, int>, int>> q;
		int arr[300][300] = { 0 };
		int visited[300][300] = { 0 };
		cin >> m; 
		cin >> x >> y >> rx >> ry;
		q.push({ {x,y},0 });
		visited[x][y] = 1;

		while (!q.empty()) {
			int nx = q.front().first.first;
			int ny = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			if (nx == rx && ny == ry) {
				cout << cnt << "\n";
				break;
			}

			for (int i = 0; i < 8; i++) {
				int nnx = nx + dx[i];
				int nny = ny + dy[i];

				if (nnx >= 0 && nnx < m && nny >= 0 && nny < m && visited[nnx][nny] == 0) {
					visited[nnx][nny] = 1;
					q.push({ {nnx,nny},cnt + 1 });
				}
			}
		}
	}
	return 0;
}
