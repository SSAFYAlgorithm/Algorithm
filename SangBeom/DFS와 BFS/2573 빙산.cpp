#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int N, M;
int MAP[301][301];
int temp[301][301] = { 0 };
int check[301][301];
void bfs(int r, int c)
{
	check[r][c] = 0;
	int visited[301][301] = { 0 };
	queue<pair<int, int>>que;
	que.push(make_pair(r, c));
	visited[r][c] = 1;
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	while (!que.empty()) {
		pair<int, int>now = que.front();que.pop();
		check[now.first][now.second] = 0;
		int cnt = 0;
		for (int i = 0;i < 4;i++) {
			int tx = now.first + dx[i];
			int ty = now.second + dy[i];
			if (MAP[tx][ty] == 0)cnt++;
		}
		temp[now.first][now.second] = MAP[now.first][now.second] - cnt;
		if (temp[now.first][now.second] < 0)temp[now.first][now.second] = 0;
		for (int i = 0;i < 4;i++) {
			int tx = now.first + dx[i];
			int ty = now.second + dy[i];
			if (tx<0 || ty<0 || tx>N || ty>M)continue;
			if (visited[tx][ty])continue;
			if (!MAP[tx][ty])continue;
			visited[tx][ty] = 1;
			que.push(make_pair(tx, ty));

		}

	}

}
int solve()
{
	int ans = 0;
	while (1)
	{


		int pos = 0;
		memset(temp, 0, sizeof(temp));
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (MAP[i][j]) {
					check[i][j] = 1;
				}
			}
		}
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (check[i][j]) {
					bfs(i, j);
					pos++;
				}
			}
		}
		if (pos >= 2)return ans;
		if (pos == 0)return 0;
		memcpy(MAP, temp, sizeof(temp));
		ans++;
	}

}


int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}
	cout << solve();
}