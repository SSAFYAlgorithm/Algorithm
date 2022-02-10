#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int arr[11][11];
int n, m, startRX, startRY, startBX, startBY, endX, endY;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int bfs() {
	queue<pair<pair<pair<int, int>, pair<int, int>>,int>> q;
	q.push({ {{startRX, startRY},{startBX, startBY} },0 });
	int visited[11][11][11][11] = { 0 };
	visited[startRX][startRY][startBX][startBY] = 1;
	while (!q.empty()) {
		int redX = q.front().first.first.first;
		int redY = q.front().first.first.second;
		int blueX = q.front().first.second.first;
		int blueY = q.front().first.second.second;
		int cnt = q.front().second;
		q.pop();

		if (cnt > 10)
			return -1;

		for (int i = 0; i < 4; i++) {
			int nredX = redX;
			int nredY = redY;
			int nblueX = blueX;
			int nblueY = blueY;
			int flagEndR = 0;
			int flagEndB = 0;
			while (true) {
				nredX += dx[i];
				nredY += dy[i];
				nblueX += dx[i];
				nblueY += dy[i];
				int flagR = 0;
				int flagB = 0;

				if (nblueX == endX && nblueY == endY) {
					flagEndB = 1;
					break;
				}
				if (nredX == endX && nredY == endY) {
					flagEndR = 1;
				}
				if (arr[nredX][nredY] == -1) {
					nredX -= dx[i];
					nredY -= dy[i];
					flagR = 1;
				}
				if (arr[nblueX][nblueY] == -1) {
					nblueX -= dx[i];
					nblueY -= dy[i];
					flagB = 1;
				}
				if (nredX == nblueX && nredY == nblueY && flagR == 1) {
					nblueX -= dx[i];
					nblueY -= dy[i];
					flagB = 1;
				}
				if (nredX == nblueX && nredY == nblueY && flagB == 1) {
					nredX -= dx[i];
					nredY -= dy[i];
					flagR = 1;
				}
				if (flagB && flagR && visited[nredX][nredY][nblueX][nblueY] == 0) {
					visited[nredX][nredY][nblueX][nblueY] = 1;
					q.push({ {{nredX, nredY},{nblueX, nblueY} },cnt + 1 });
					break;
				}
				if (flagB && flagR && visited[nredX][nredY][nblueX][nblueY] == 1) {
					break;
				}
			}
			if (flagEndR == 1 && flagEndB == 0) {
				if (cnt >= 10)
					return -1;
				return cnt + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	char temp;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == '#')
				arr[i][j] = -1;
			else if (temp == '.')
				arr[i][j] = 0;
			else if (temp == 'R') {
				arr[i][j] = 0;
				startRX = i;
				startRY = j;
			}
			else if (temp == 'B') {
				arr[i][j] = 0;
				startBX = i;
				startBY = j;
			}
			else if (temp == 'O') {
				arr[i][j] = 1;
				endX = i;
				endY = j;
			}
		}
	}
	ans = bfs();
	cout << ans;
	return 0;
}