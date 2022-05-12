#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N;
int map[510][510];
int dp[510][510];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

struct info {
	int y, x, food;
};

struct comp {
	bool operator()(info right, info left) {
		if (left.food == right.food) {
			if (left.y == right.y) {
				return left.x < right.x;
			}
			return left.y < right.y;
		}
		return left.food < right.food;
	}
};
priority_queue<info, vector<info>, comp> pq;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			pq.push({ y,x,map[y][x] });
		}
	}
	int res = 0;
	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int food = pq.top().food;
		pq.pop();
		int MAX = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[ny][nx] == food) continue;
			if (dp[ny][nx] > MAX) {
				MAX = dp[ny][nx];
			}
		}
		dp[y][x] = MAX + 1;
		if (dp[y][x] > res) {
			res = dp[y][x];
		}
	}

	cout << res;

	return 0;
}