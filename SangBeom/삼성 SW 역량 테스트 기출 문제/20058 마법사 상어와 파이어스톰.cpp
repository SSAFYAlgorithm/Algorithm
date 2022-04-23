#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<cmath>
using namespace std;
int N, Q;
int SIZE;
int MAP[65][65];
int temp[65][65] = { 0 };
int temp2[65][65] = { 0 };
void angle(int r, int c, int L) {
	memset(temp, 0, sizeof(temp));
	memset(temp2, 0, sizeof(temp2));
	int num = pow(2, L);  
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num;j++) {
			temp[i][j] = MAP[i + r][j + c];
		}
	}
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num;j++) {
			temp2[i][j] = temp[num - 1 - j][i];
		}
	}
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num;j++) {
			MAP[i + r][j + c] = temp2[i][j];
		}
	}
}
void rotate(int L) {
	for (int i = 0;i < SIZE;i += pow(2, L)) {
		for (int j = 0;j < SIZE;j += pow(2, L)) {
			angle(i, j, L);
		}
	}
}
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int tmp[65][65] = { 0 };
void melt()
{
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0;i < pow(2, N);i++) {
		for (int j = 0;j < pow(2, N);j++) {
			if (!MAP[i][j])continue;
			int cnt = 0;
			for (int k = 0;k < 4;k++) {
				int tx = i + dx[k];
				int ty = j + dy[k];
				if (tx < 0 || ty < 0 || tx >= SIZE || ty >= SIZE) {
					continue;
				}
				if (MAP[tx][ty])cnt++;
			}
			if (cnt < 3)tmp[i][j]--;
		}
	}
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			MAP[i][j] += tmp[i][j];
		}
	}
}
int check[65][65];
int visited[65][65] = { 0 };
int bfs(int r, int c)
{
	queue<pair<int, int>>que;
	que.push(make_pair(r, c));
	memset(visited, 0, sizeof(visited));
	visited[r][c] = 1;
	check[r][c] = 1;
	while (!que.empty()) {
		pair<int, int>now = que.front();que.pop();
		for (int i = 0;i < 4;i++) {
			int tx = now.first + dx[i];
			int ty = now.second + dy[i];
			if (tx < 0 || ty < 0 || tx >= pow(2, N) || ty >= pow(2, N))continue;
			if (!MAP[tx][ty])continue;
			if (visited[tx][ty])continue;
			visited[tx][ty] = 1;
			check[tx][ty] = 1;
			que.push(make_pair(tx, ty));
		}
	}
	int sum = 0;
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			if (visited[i][j])sum++;
		}
	}
	return sum;
}
void solve()
{

	for (int i = 0;i < Q;i++) {
		int L;
		cin >> L;
		if (L != 0) {
			rotate(L);
		}
		melt();
	}
	int sum = 0;
	int maxValue = 0;
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			sum += MAP[i][j];
			if (!check[i][j] && MAP[i][j]) {
				int now = bfs(i, j);
				if (now > maxValue)maxValue = now;
			}
		}
	}
	cout << sum << endl;
	cout << maxValue;

}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> Q;
	int cnt = 1;
	SIZE = pow(2, N);
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			cin >> MAP[i][j];

		}
	}
	solve();
}