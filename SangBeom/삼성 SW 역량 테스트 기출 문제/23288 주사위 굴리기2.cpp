#include<iostream>
#include<string.h>
#include<queue>
#define MAXSIZE 21
using namespace std;

int N, M, K;
int MAP[MAXSIZE][MAXSIZE];
int visited[MAXSIZE][MAXSIZE];
int nowx, nowy;
int dice[6] = { 1,2,3,4,5,6 };
int dx[] = { 0,1,0,-1 };//øÏ«œ¡¬ªÛ
int dy[] = { 1,0,-1,0 };
int dir;
int back;
void dicemove(int dir)
{
	int d0 = dice[0];//1 ≈æ
	int d1 = dice[1];//2 ¿ß
	int d2 = dice[2];//3 ø¿
	int d3 = dice[3];//4 øﬁ
	int d4 = dice[4];//5 æ∆∑°
	int d5 = dice[5];//6 πŸ≈“
	if (dir == 0) {
		dice[0] = d3;
		dice[2] = d0;
		dice[3] = d5;
		dice[5] = d2;
		return;
	}
	if (dir == 1) {
		dice[0] = d1;
		dice[4] = d0;
		dice[1] = d5;
		dice[5] = d4;
		return;
	}
	if (dir == 2) {
		dice[0] = d2;
		dice[3] = d0;
		dice[2] = d5;
		dice[5] = d3;
		return;
	}
	if (dir == 3) {
		dice[0] = d4;
		dice[4] = d5;
		dice[1] = d0;
		dice[5] = d1;
		return;
	}
}
int calc(int r, int c)
{
	queue<pair<int, int>>que;
	que.push(make_pair(r, c));
	memset(visited, 0, sizeof(visited));
	visited[r][c] = 1;
	int num = MAP[r][c];
	while (!que.empty())
	{
		pair<int, int>now = que.front();que.pop();
		for (int i = 0;i < 4;i++) {
			int tx = now.first + dx[i];
			int ty = now.second + dy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M)continue;
			if (MAP[tx][ty] != num)continue;
			if (visited[tx][ty])continue;
			visited[tx][ty] = 1;
			que.push(make_pair(tx, ty));
		}

	}
	int cnt = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (visited[i][j])cnt++;
		}
	}
	return cnt;
}
int reversedir() {
	if (dir == 0)return 2;
	if (dir == 1) return 3;
	if (dir == 2)return 0;
	if (dir == 3)return 1;
}
void solve()
{
	nowx = 0, nowy = 0; dir = 0;
	back = dice[5];
	int ans = 0;
	for (int i = 0;i < K;i++)
	{
		int tx = dx[dir] + nowx;
		int ty = dy[dir] + nowy;
		if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
			dir = reversedir();
			tx = dx[dir] + nowx;
			ty = dy[dir] + nowy;
		}
		dicemove(dir);
		back = dice[5];
		if (MAP[tx][ty] < back) {
			dir++;
		}
		else if (MAP[tx][ty] > back) {
			dir--;
		}
		if (dir > 3)dir = 0;
		if (dir < 0)dir = 3;
		nowx = tx;
		nowy = ty;
		ans += (MAP[nowx][nowy] * calc(nowx, nowy));
	}
	cout << ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}
	solve();

}