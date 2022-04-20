#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int N;
int MAP[101][101];
int temp[101][101];
int minValue = 101;
int maxValue = 0;
void bfs(int r, int c)
{
	queue<pair<int, int>>que;
	que.push(make_pair(r, c));
	temp[r][c] = 0;
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	while (!que.empty()) {
		pair<int, int>now = que.front();que.pop();
		for (int i = 0;i < 4;i++) {
			int tx = now.first + dx[i];
			int ty = now.second + dy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
			if (temp[tx][ty] == 1) {
				que.push(make_pair(tx, ty));
				temp[tx][ty] = 0;
			}
		}

	}

}
int solve()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (MAP[i][j] < minValue) {
				minValue = MAP[i][j];
			}

			if (MAP[i][j] > maxValue) {
				maxValue = MAP[i][j];
			}
		}
	}

	int max = -1;
	for (int t = minValue; t <= maxValue;t++) {
		memset(temp, 0, sizeof(temp));
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (MAP[i][j] >= t) {
					temp[i][j] = 1;
				}
			}
		}
		int cnt = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (temp[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (max < cnt)max = cnt;
	}
	return max;
}


int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];

		}
	}
	cout << solve();
}