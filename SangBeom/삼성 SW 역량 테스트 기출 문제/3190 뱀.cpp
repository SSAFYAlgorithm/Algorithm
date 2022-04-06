#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int MAP[101][101];
int N;
int changeDir(int dirNow, char dir) {
	if (dir == 'D') {
		if (dirNow == 0) return 3;
		else if (dirNow == 1)return 0;
		else if (dirNow == 2)return 1;
		else if (dirNow == 3)return 2;

	}
	if (dir == 'L') {
		if (dirNow == 0) return 1;
		else if (dirNow == 1)return 2;
		else if (dirNow == 2)return 3;
		else if (dirNow == 3)return 0;

	}
}
int move()
{
	int m;
	cin >> m;
	int dx[4] = { -1,0,1,0 };//상좌하우
	int dy[4] = { 0,-1,0,1 };
	int dirNow = 3;
	int x = 1, y = 1;
	int ans = 0;
	queue<pair<int, int>>que;
	que.push(pair<int, int>(1, 1));
	int prevtime = 0;
	int time;
	for (int t = 0;t < m;t++) {
		cin >> time;
		for (int i = 1;i <= time - prevtime;i++) {
			int tx = dx[dirNow] * i + x;
			int ty = dy[dirNow] * i + y;
			if (tx<1 || ty<1 || tx>N || ty>N) {
				ans += i;
				return ans;
			}
			if (MAP[tx][ty] == 1) {
				ans += i;
				return ans;
			}
			if (MAP[tx][ty] == 2) {
				que.push(pair<int, int>(tx, ty));
				MAP[tx][ty] = 1;
			}
			else if (MAP[tx][ty] == 0) {
				MAP[que.front().first][que.front().second] = 0;
				que.pop();
				que.push(pair<int, int>(tx, ty));
				MAP[tx][ty] = 1;
			}
		}
		ans += (time - prevtime);
		x = dx[dirNow] * (time - prevtime) + x;
		y = dy[dirNow] * (time - prevtime) + y;
		char dir;
		cin >> dir;
		int now = changeDir(dirNow, dir);
		dirNow = now;
		prevtime = time;
	}
	int i = 1;
	while (1)
	{
		int tx = dx[dirNow] * i + x;
		int ty = dy[dirNow] * i + y;
		if (tx<1 || ty<1 || tx>N || ty>N) {
			ans += i;
			return ans;
		}
		if (MAP[tx][ty] == 1) {
			ans += i;
			return ans;
		}
		if (MAP[tx][ty] == 2) {
			que.push(pair<int, int>(tx, ty));
			MAP[tx][ty] = 1;
		}
		else if (MAP[tx][ty] == 0) {
			MAP[que.front().first][que.front().second] = 0;
			que.pop();
			que.push(pair<int, int>(tx, ty));
			MAP[tx][ty] = 1;
		}
		i++;
	}

}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	int k;
	cin >> k;
	for (int i = 0;i < k;i++) {
		int x, y;
		cin >> x >> y;
		MAP[x][y] = 2;//사과

	}
	MAP[1][1] = 1;
	int res = move();
	cout << res;
}