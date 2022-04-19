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
				int cnt = 0;
				for (int k = 0;k < 4;k++) {
					int tr = dr[k] + i;
					int tc = dc[k] + j;
					if (tr < 0 || tc < 0 || tr >= R || tc >= C) continue;
					if (MAP[tr][tc] == -1) continue;
					temp[tr][tc] += MAP[i][j] / 5;
					cnt += 1;
				}
				temp[i][j] += (MAP[i][j] - (MAP[i][j] / 5 * cnt));
			}
		}
	}
	memcpy(MAP, temp, sizeof(MAP));
	MAP[r1][0] = -1;
	MAP[r2][0] = -1;
}
void clean()
{
	/*int nowX = r1;
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
	MAP[r1][0] = -1;
	MAP[r1][1] = 0;
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

	MAP[r2][0] = -1;
	MAP[r2][1] = 0;*/
	// 위의 공기 순환 (반시계)
	for (int i = r1 - 1; i > 0; i--)
		MAP[i][0] = MAP[i - 1][0];
	for (int i = 0; i < C - 1; i++)
		MAP[0][i] = MAP[0][i + 1];
	for (int i = 1; i <= r1; i++)
		MAP[i - 1][C - 1] = MAP[i][C - 1];
	for (int i = C - 1; i > 1; i--)
		MAP[r1][i] = MAP[r1][i - 1];
	MAP[r1][1] = 0;

	for (int i = r2 + 1; i < R - 1; i++)
		MAP[i][0] = MAP[i + 1][0];
	for (int i = 0; i < C - 1; i++)
		MAP[R - 1][i] = MAP[R - 1][i + 1];
	for (int i = R - 1; i >= r2; i--)
		MAP[i][C - 1] = MAP[i - 1][C - 1];
	for (int i = C - 1; i > 1; i--)
		MAP[r2][i] = MAP[r2][i - 1];
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
	freopen("input.txt", "r", stdin);
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