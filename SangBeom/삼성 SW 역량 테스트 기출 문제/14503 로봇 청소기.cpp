#include <iostream>
#include <vector>

using namespace std;
int MAP[51][51];
int clear[51][51];
int N, M;
int r, c, d;
int dir(int direction)
{
	if (direction == 0) return 1;
	else if (direction == 1) return 2;
	else if (direction == 2) return 3;
	else if (direction == 3) return 0;
	else if (direction == 4) return 1;
	else if (direction == 5) return 2;
	else if (direction == 6) return 3;
	else if (direction == 7) return 0;
}

void solve()
{
	int dr[4] = { -1,0,1,0 };//ºÏ¼­³²µ¿
	int dc[4] = { 0,-1,0,1 };
	MAP[r][c] = 2;
	int cnt = 0;
	int flag = 0;
	while (1)
	{
		flag = 0;
		for (int i = 0;i < 4;i++) {
			int nowd = dir(i + d);
			int tr = dr[nowd] + r;
			int tc = dc[nowd] + c;
			if (MAP[tr][tc] == 1 || MAP[tr][tc] == 2) {
				continue;
			}
			if (MAP[tr][tc] == 0) {
				r = tr;	c = tc; d = nowd;
				MAP[tr][tc] = 2;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			if (d == 0) {
				r++;
			}
			else if (d == 1) {
				c++;
			}
			else if (d == 2) {
				r--;
			}
			else if (d == 3) {
				c--;
			}
			if (MAP[r][c] == 1) break;

		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	cin >> r >> c >> d;

	if (d == 3)d = 1;
	else if (d == 1)d = 3;
	clear[r][c] = 1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				clear[i][j] = -1;
			}
		}
	}
	solve();
	int ans = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (MAP[i][j] == 2) {
				ans++;
			}
		}
	}
	cout << ans;
}