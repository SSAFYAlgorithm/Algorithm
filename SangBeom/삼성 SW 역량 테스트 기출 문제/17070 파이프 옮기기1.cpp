#include<iostream>
#include<queue>
using namespace std;

int N;
int MAP[17][17];
int dx[] = { 0,1,1 };
int dy[] = { 1,1,0 };
struct pipe {
	int r, c, state;
};
int findWall(int r, int c) {
	int dr[] = { -1,0 };
	int dc[] = { 0,-1 };

	for (int i = 0;i < 2;i++) {
		int tx = dr[i] + r;
		int ty = dc[i] + c;
		if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
		if (MAP[tx][ty])return 0;
	}
	return 1;
}
void solve()
{
	int cnt = 0;
	queue<pipe>que;
	que.push({ 0,1,0 });
	while (!que.empty()) {
		pipe now = que.front();que.pop();
		if (now.state == 0) {//->
			for (int i = 0;i < 2;i++) {
				int tx = now.r + dx[i];
				int ty = now.c + dy[i];
				if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
				if (MAP[tx][ty])continue;
				if (i == 0 && tx == N - 1 && ty == N - 1)cnt++;
				else if (i == 1 && tx == N - 1 && ty == N - 1 && findWall(tx, ty))cnt++;
				else {
					if (i == 0)que.push({ tx,ty,0 });
					if (i == 1 && findWall(tx, ty))que.push({ tx,ty,1 });
				}
			}
		}
		else if (now.state == 1) {//´ë°¢
			for (int i = 0;i < 3;i++) {
				int tx = now.r + dx[i];
				int ty = now.c + dy[i];
				if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
				if (MAP[tx][ty])continue;
				if ((i == 0 || i == 2) && tx == N - 1 && ty == N - 1)cnt++;
				else if (i == 1 && tx == N - 1 && ty == N - 1 && findWall(tx, ty))cnt++;
				else {
					if (i == 0)que.push({ tx,ty,0 });
					if (i == 1 && findWall(tx, ty))que.push({ tx,ty,1 });
					if (i == 2)que.push({ tx,ty,2 });
				}
			}
		}
		else if (now.state == 2) {//¹Ø
			for (int i = 1;i < 3;i++) {
				int tx = now.r + dx[i];
				int ty = now.c + dy[i];
				if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
				if (MAP[tx][ty])continue;
				if (i == 2 && tx == N - 1 && ty == N - 1)cnt++;
				else if (i == 1 && tx == N - 1 && ty == N - 1 && findWall(tx, ty))cnt++;
				else {
					if (i == 1 && findWall(tx, ty))que.push({ tx,ty,1 });
					if (i == 2)que.push({ tx,ty,2 });
				}
			}
		}
	}
	cout << cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
		}
	}
	solve();
}