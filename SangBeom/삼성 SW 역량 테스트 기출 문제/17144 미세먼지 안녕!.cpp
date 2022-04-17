#include<iostream>
#include<string.h>

using namespace std;
int R, C, T;
int MAP[51][51];
int r1, r2;
int temp[51][51];
void dust()
{
	memset(temp, 0, sizeof(temp));
	int dr[4] = { -1,0,1,0 };
	int dc[4] = { 0,-1,0,1 };
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (MAP[i][j] > 0) {
				int sum = 0;
				for (int k = 0;k < 4;k++) {
					int tr = dr[k] + i;
					int tc = dc[k] + j;
					if (tr < 0 || tc < 0 || tr >= R || tc >= C) continue;
					if (MAP[tr][tc] == -1) continue;
					temp[tr][tc] += MAP[i][j] / 5;
					sum += MAP[i][j] / 5;
				}
				temp[i][j] += (MAP[i][j] - sum);
			}
		}
	}
	memcpy(MAP, temp, sizeof(MAP));
	MAP[r1][0] = -1;
	MAP[r2][0] = -1;
}
void clean()
{
	int nowX = r1;
	int nowY = 0;
	int sr[4] = { -1,0,1,0 };
	int sc[4] = { 0,1,0,-1 };
	for (int i = 0;i < 4;i++) {
		for (int j = 1;j < 50;j++) {
			int sx = nowX + sr[i] * j;
			int sy = nowY + sc[i] * j;

			if (sx < 0 || sy < 0 || sx > r1 || sy >= C || MAP[sx][sy] == -1) {
				nowX = sx - sr[i];
				nowY = sy - sc[i];
				break;
			}
			MAP[sx - sr[i]][sy - sc[i]] = MAP[sx][sy];
		}
	}
	nowX = r2;
	nowY = 0;
	int er[4] = { 1,0,-1,0 };
	int ec[4] = { 0,1,0,-1 };
	for (int i = 0;i < 4;i++) {
		for (int j = 1;j < 50;j++) {
			int sx = nowX + er[i] * j;
			int sy = nowY + ec[i] * j;

			if (sx < r2 || sy < 0 || sx >= R || sy >= C || MAP[sx][sy] == -1) {
				nowX = sx - er[i];
				nowY = sy - ec[i];
				break;
			}
			MAP[sx - er[i]][sy - ec[i]] = MAP[sx][sy];
		}
	}
	MAP[r1][0] = -1;
	MAP[r2][0] = -1;
	MAP[r1][1] = 0;
	MAP[r2][1] = 0;
}
int solve()
{
	for (int i = 0; i < T;i++) {
		dust();
		clean();
	}
	int sum = 0;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (MAP[i][j] > 0) {
				sum += MAP[i][j];
			}
		}
	}
	return sum;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> R >> C >> T;
	int flag = 1;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == -1) {
				if (flag) {
					r1 = i;flag = 0;
					r2 = i + 1;
				}

			}
		}
	}
	int res = solve();
	cout << res;
	return 0;
}