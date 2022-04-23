#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int N;
int MAP[21][21];
int SIZE = 2;
int sizeEat;
int sx, sy;
int t = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int possible(int r, int c) {
	int check[21][21] = { 0 };
	check[sx][sy] = 1;
	queue<pair<int, int>>que;
	que.push(make_pair(sx, sy));

	while (!que.empty()) {
		pair<int, int>now = que.front(); que.pop();
		for (int i = 0;i < 4;i++) {
			int tx = dx[i] + now.first;
			int ty = dy[i] + now.second;
			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			if (MAP[tx][ty] > SIZE)continue;
			if (check[tx][ty])continue;
			check[tx][ty] = check[now.first][now.second] + 1;
			que.push(make_pair(tx, ty));
			if (tx == r && ty == c) {

				return check[tx][ty] - 1;
			}
		}
	}
	return -1;
}
int check()
{
	int cnt = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (MAP[i][j] == 9)continue;
			if (MAP[i][j] < SIZE && MAP[i][j] != 0) {
				cnt++;
			}
		}
	}
	return cnt;
}
void solve()
{
	while (1) {
		int now = check();
		if (now == 0) {
			cout << t;
			break;
		}
		else if (now >= 1) {
			int sum = 10000;
			int x, y;
			for (int i = 0;i < N;i++) {
				for (int j = 0;j < N;j++) {
					if (MAP[i][j] < SIZE && MAP[i][j] != 0) {
						int now = possible(i, j);
						if (sum > now && now != -1) {
							x = i;y = j;
							sum = now;
						}
					}
				}
			}
			if (sum == 10000) {
				cout << t; break;
			}
			sx = x; sy = y; t += sum;
			MAP[sx][sy] = 0;
		}
		sizeEat++;
		if (sizeEat == SIZE) {
			SIZE++;
			sizeEat = 0;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				sx = i; sy = j;
				MAP[i][j] = 0;
			}
		}
	}
	solve();
}