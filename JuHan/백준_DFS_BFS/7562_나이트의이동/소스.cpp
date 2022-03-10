#include <iostream>
#include <queue>

using namespace std;

int chess[301][301];
bool visited[301][301];
int direct[8][2] = {
	-1,-2,
	-2,-1,
	-2,1,
	-1,2,
	1,2,
	2,1,
	2,-1,
	1,-2
};
int curY, curX, tarY, tarX;
int times;
int l;
queue<pair<int, int>> q;


void bfs(int y, int x) {
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a == tarY && b == tarX) {
			cout << chess[a][b] << "\n";
			while (!q.empty()) {
				q.pop();
			}
			break;
		}
		for (int i = 0; i < 8; i++) {
			int da = a + direct[i][0];
			int db = b + direct[i][1];
			if (da >= 0 && da < l && db >= 0 && db < l && !visited[da][db]) {
				q.push({ da,db });
				visited[da][db] = true;
				chess[da][db] = chess[a][b] + 1;
			}
		}
	}
}

void init() {
	while (!q.empty()) {
		q.pop();
	}
	for (int y = 0; y < 301; y++) {
		for (int x = 0; x < 301; x++) {
			visited[y][x] = false;
			chess[y][x] = 0;
		}
	}
}

int main() {
	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> l;
		cin >> curY >> curX;
		cin >> tarY >> tarX;

		bfs(curY, curX);
		init();
	}

	return 0;
}