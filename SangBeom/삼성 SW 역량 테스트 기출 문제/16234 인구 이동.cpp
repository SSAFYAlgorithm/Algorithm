#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int N, L, R;
int MAP[51][51] = { 0 };
int check[51][51] = { 0 };
int visited[51][51] = { 0 };
int flag;
void calc()
{
	int sum = 0;
	int cnt = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (check[i][j]) {
				sum += MAP[i][j];
				cnt++;
			}
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (check[i][j]) {
				MAP[i][j] = sum / cnt;
				visited[i][j] = 1;
			}
		}
	}
	memset(check, 0, sizeof(check));
}
void bfs(int x, int y)
{

	queue<pair<int, int>>que;
	que.push(pair<int, int>(x, y));
	check[x][y] = 1;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	while (!que.empty()) {
		pair<int, int>now = que.front();que.pop();
		for (int i = 0;i < 4;i++) {
			int tx = dx[i] + now.first;
			int ty = dy[i] + now.second;
			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			if (check[tx][ty])continue;
			if (visited[tx][ty])continue;
			if (abs(MAP[now.first][now.second] - MAP[tx][ty]) >= L &&
				abs(MAP[now.first][now.second] - MAP[tx][ty]) <= R) {
				que.push(pair<int, int>(tx, ty));
				check[tx][ty] = 1;
				flag = 1;
			}
		}
	}
	if (!flag) {
		check[x][y] = 0;
		return;
	}
	calc();
}

int solve()
{
	int ans = 0;
	while (1) {
		int flag2 = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (!visited[i][j]) {
					flag = 0;
					bfs(i, j);
					if (flag) {
						flag2 = 1;
					}
				}
			}
		}
		if (!flag2)break;
		memset(visited, 0, sizeof(visited));
		ans++;
	}
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> L >> R;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
		}
	}
	cout << solve();
}