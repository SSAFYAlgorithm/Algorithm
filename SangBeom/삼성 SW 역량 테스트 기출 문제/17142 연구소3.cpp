#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

vector<pair<int, int>>virus;
int MAP[51][51];
int N, M;
int checked[10];
int cnt[51][51];
int bfs()
{
	memset(cnt, 0, sizeof(cnt));
	queue<pair<int, int>>que;
	for (int i = 0;i < virus.size();i++) {
		if (checked[i]) {
			que.push(pair<int, int>(virus[i].first, virus[i].second));
			cnt[virus[i].first][virus[i].second] = 1;
		}
	}
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	int maxValue = 0;
	while (!que.empty()) {
		pair<int, int>now = que.front();que.pop();

		for (int i = 0;i < 4;i++) {
			int tx = dx[i] + now.first;
			int ty = dy[i] + now.second;
			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			if (MAP[tx][ty] == 1)continue;
			if (cnt[tx][ty])continue;
			cnt[tx][ty] = cnt[now.first][now.second] + 1;
			que.push(pair<int, int>(tx, ty));
		}
	}
	int flag = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (MAP[i][j] == 1 || MAP[i][j] == 2)continue;
			if (!cnt[i][j])return -1;
			if (cnt[i][j] > maxValue) {
				maxValue = cnt[i][j];
				flag = 1;
			}
		}
	}
	if (flag) {
		return maxValue - 1;
	}
	else return maxValue;
}
int minValue = 21e4;
int flag = 0;
void dfs(int level, int s)
{
	if (level == M) {
		int now = bfs();
		if (now != -1) {
			flag = 1;
			if (now < minValue)minValue = now;
		}
		return;
	}
	for (int i = s; i < virus.size();i++) {
		checked[i] = 1;
		dfs(level + 1, i + 1);
		checked[i] = 0;
	}
}

void solve() {
	dfs(0, 0);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				virus.push_back(pair<int, int>(i, j));
			}
		}
	}

	solve();
	if (flag)cout << minValue;
	else cout << -1;
}