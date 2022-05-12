#include<iostream>
#include<string.h>
#include<queue>
#define MAXSIZE 21
using namespace std;

int N, M, K;
int MAP[MAXSIZE][MAXSIZE];
int visited[MAXSIZE][MAXSIZE];
int nowx, nowy;
int dice[6] = { 0, };
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

int movedir(int cmd)
{
	if (cmd == 1) return 0;//ø¿
	if (cmd == 2) return 2;//øﬁ
	if (cmd == 3) return 3;//¿ß
	if (cmd == 4) return 1;//æ∆∑°
}
void solve()
{


	for (int i = 0;i < K;i++)
	{
		int cmd;cin >> cmd;
		dir = movedir(cmd);
		int tx = nowx + dx[dir];
		int ty = nowy + dy[dir];
		if (tx < 0 || ty < 0 || tx >= N || ty >= M)continue;
		dicemove(dir);

		nowx = tx;nowy = ty;
		if (!MAP[nowx][nowy])MAP[nowx][nowy] = dice[5];
		else {
			dice[5] = MAP[nowx][nowy];
			MAP[nowx][nowy] = 0;
		}
		cout << dice[0] << "\n";
	}

}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> nowx >> nowy >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}
	solve();

}