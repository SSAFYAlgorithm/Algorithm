#include<iostream>
#include<string.h>
#define MAXINDEX 500
using namespace std;


int N;
int MAP[MAXINDEX][MAXINDEX];
int visited[MAXINDEX][MAXINDEX];
int sr, sc;
int res;
void tonado(int r, int c, int d)
{
	int sand = MAP[r][c];
	MAP[r][c] = 0;
	int tmp[5][5] = { 0 };
	int cnt = 0;
	int rotate = d;
	tmp[0][2] = (sand * 2) / 100;
	tmp[4][2] = (sand * 2) / 100;
	tmp[1][1] = (sand * 10) / 100;
	tmp[3][1] = (sand * 10) / 100;
	tmp[1][2] = (sand * 7) / 100;
	tmp[3][2] = (sand * 7) / 100;
	tmp[1][3] = (sand * 1) / 100;
	tmp[3][3] = (sand * 1) / 100;
	tmp[2][0] = (sand * 5) / 100;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cnt += tmp[i][j];
		}
	}
	tmp[2][1] = sand - cnt;
	int tmp2[5][5];
	while (rotate) {
		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 5;j++) {
				tmp2[i][j] = tmp[j][4 - i];
			}
		}
		memcpy(tmp, tmp2, sizeof(tmp));
		rotate--;
	}
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (r + i - 2 < 0 || c + j - 2 < 0 || r + i - 2 >= N || c + j - 2 >= N) {
				res += tmp[i][j];
				continue;
			}
			MAP[r + i - 2][c + j - 2] += tmp[i][j];
		}
	}
}
void solve()
{
	int dr[] = { 0,1,0,-1 };//ÁÂÇÏ¿ì»ó
	int dc[] = { -1,0,1,0 };
	int dir = 0;
	while (!(sr == 0 && sc == 0)) {
		sr = sr + dr[dir];
		sc = sc + dc[dir];
		visited[sr][sc] = 1;
		tonado(sr, sc, dir);
		if (!visited[sr + dr[(dir + 1) % 4]][sc + dc[(dir + 1) % 4]]) dir++;
		if (dir >= 4)dir = 0;
	}
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
	sr = N / 2;
	sc = N / 2;
	visited[sr][sc] = 1;
	solve();
	cout << res;
}