#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int N, M;
char MAP[51][51];
int visited[51][51];
struct findGold {
	int r;
	int c;
	int cnt;
};
int bfs(int r, int c)
{
	queue<findGold>que;
	int maxValue = -1;
	memset(visited, 0, sizeof(visited));
	visited[r][c] = 1;
	que.push({ r,c,1 });
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	while (!que.empty()) {
		findGold now = que.front();que.pop();
		if (maxValue < now.cnt)maxValue = now.cnt;
		for (int i = 0;i < 4;i++) {
			int tx = dx[i] + now.r;
			int ty = dy[i] + now.c;
			if (tx < 0 || ty < 0 || tx >= N || ty >= M)continue;
			if (MAP[tx][ty] == 'W')continue;
			if (visited[tx][ty])continue;
			visited[tx][ty] = 1;
			que.push({ tx,ty,now.cnt + 1 });
		}
	}
	return maxValue - 1;
}
void solve()
{
	int maxValue = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (MAP[i][j] == 'L') {

				int now = bfs(i, j);
				if (now > maxValue)maxValue = now;

			}
		}
	}
	cout << maxValue;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;
		for (int j = 0;j < M;j++) {
			MAP[i][j] = str[j];
		}
	}
	solve();
}