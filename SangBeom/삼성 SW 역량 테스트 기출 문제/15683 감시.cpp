#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int MAP[9][9];
int temp[9][9];

struct camera {
	int r;
	int c;
	int num;
};
int N, M;
vector<camera>cctv;
int dir[8];
void up(int r, int c)
{
	for (int k = r - 1;k >= 0;k--) {
		if (k < 0)break;
		if (temp[k][c] == 6)break;
		if (temp[k][c])continue;
		temp[k][c] = 7;
	}
}
void down(int r, int c)
{
	for (int k = r + 1;k <= N;k++) {
		if (k >= N)break;
		if (temp[k][c] == 6)break;
		if (temp[k][c])continue;
		temp[k][c] = 7;
	}
}
void left(int r, int c)
{
	for (int k = c - 1;k >= 0;k--) {
		if (k < 0)break;
		if (temp[r][k] == 6)break;
		if (temp[r][k])continue;
		temp[r][k] = 7;
	}
}
void right(int r, int c)
{
	for (int k = c + 1;k < M;k++) {
		if (k >= M)break;
		if (temp[r][k] == 6)break;
		if (temp[r][k])continue;
		temp[r][k] = 7;
	}
}
int minFind()
{
	memcpy(temp, MAP, sizeof(temp));
	for (int i = 0;i < cctv.size() - 1;i++) {
		camera now = cctv[i];
		if (now.num == 1) {
			int dx[] = { -1,0,1,0 };
			int dy[] = { 0,-1,0,1 };
			int k = 1;
			while (1)
			{
				int tx = dx[dir[i]] * k + now.r;
				int ty = dy[dir[i]] * k + now.c;
				if (temp[tx][ty] == 6)break;
				if (tx < 0 || ty < 0 || tx >= N || ty >= M)break;
				if (temp[tx][ty] == 1 || temp[tx][ty] == 2 || temp[tx][ty] == 3 || temp[tx][ty] == 4 || temp[tx][ty] == 5) {
					k++; continue;
				}
				temp[tx][ty] = 7;
				k++;
			}
		}
		if (now.num == 2) {
			if (dir[i] == 0) {//»óÇÏ
				up(now.r, now.c);
				down(now.r, now.c);
			}
			else if (dir[i] == 1) {//ÁÂ¿ì
				left(now.r, now.c);
				right(now.r, now.c);
			}
		}
		if (now.num == 3) {
			//¿ì»ó
			if (dir[i] == 0) {
				right(now.r, now.c);
				up(now.r, now.c);
			}
			else if (dir[i] == 1) {//»óÁÂ
				up(now.r, now.c);
				left(now.r, now.c);
			}
			else if (dir[i] == 2) {//ÁÂÇÏ
				left(now.r, now.c);
				down(now.r, now.c);
			}
			else if (dir[i] == 3) {//¿ìÇÏ
				right(now.r, now.c);
				down(now.r, now.c);
			}
		}
		else if (now.num == 4) {
			if (dir[i] == 0) {//ÁÂ»ó¿ì
				left(now.r, now.c);
				right(now.r, now.c);
				up(now.r, now.c);
			}
			else if (dir[i] == 1) {//»óÁÂÇÏ
				left(now.r, now.c);
				up(now.r, now.c);
				down(now.r, now.c);
			}
			else if (dir[i] == 2) {//ÁÂÇÏ¿ì
				left(now.r, now.c);
				down(now.r, now.c);
				right(now.r, now.c);
			}
			else if (dir[i] == 3) {//ÇÏ¿ì»ó
				down(now.r, now.c);
				right(now.r, now.c);
				up(now.r, now.c);
			}
		}
		else if (now.num == 5) {
			down(now.r, now.c);
			right(now.r, now.c);
			up(now.r, now.c);
			left(now.r, now.c);
		}
	}
	int cnt = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (temp[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}
int minValue = 21e5;
void dfs(int level, int num)
{
	if (level + 1 == cctv.size()) {
		int now = minFind();
		if (now < minValue) {
			minValue = now;
		}
		return;
	}
	if (num == 1 || num == 3 || num == 4) {
		for (int i = 0;i < 4;i++) {
			dir[level] = i;
			dfs(level + 1, cctv[level + 1].num);

		}
	}
	else if (num == 2) {
		for (int i = 0;i < 2;i++) {
			dir[level] = i;
			dfs(level + 1, cctv[level + 1].num);
		}
	}
	else if (num == 5) {
		dir[level] = 0;
		dfs(level + 1, cctv[level + 1].num);
	}
}

void solve()
{
	cctv.push_back({ 0,0,0 });
	dfs(0, cctv[0].num);
	cout << minValue;
}
int main()
{
	//	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] && MAP[i][j] != 6) {
				cctv.push_back({ i,j,MAP[i][j] });
			}
		}
	}
	solve();
}