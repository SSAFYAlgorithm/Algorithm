#include<iostream>

using namespace std;
pair<int, int>MAP[4][4];
int sx, sy, sdir;
int dx[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,0,-1,-1,-1,0,1,1,1 };

void moveFish(int nowsx, int nowsy) {
	for (int f = 1;f <= 16;f++) {
		int flag = 0;
		for (int i = 0;i < 4;i++) {
			for (int j = 0;j < 4;j++) {
				if (MAP[i][j].first == f && !flag) {
					while (1) {
						int tx = i + dx[MAP[i][j].second];
						int ty = j + dy[MAP[i][j].second];
						if (tx < 0 || ty < 0 || tx >= 4 || ty >= 4) {
							MAP[i][j].second++;
							if (MAP[i][j].second > 8)MAP[i][j].second = 1;
							continue;
						}
						else if (tx == nowsx && ty == nowsy) {
							MAP[i][j].second++;
							if (MAP[i][j].second > 8)MAP[i][j].second = 1;
							continue;
						}
						pair<int, int>temp;
						temp.first = MAP[i][j].first; temp.second = MAP[i][j].second;
						MAP[i][j].first = MAP[tx][ty].first;
						MAP[i][j].second = MAP[tx][ty].second;
						MAP[tx][ty].first = temp.first;
						MAP[tx][ty].second = temp.second;
						flag = 1;
						break;
					}
				}
			}
		}
	}
}

int maxValue = -1;
void dfs(int nowsx, int nowsy, int nowdir, int res) {
	pair<int, int>tempArr[4][4];
	memcpy(tempArr, MAP, sizeof(tempArr));
	int tmp = MAP[nowsx][nowsy].first;
	res += tmp;
	if (maxValue < res)maxValue = res;
	nowdir = MAP[nowsx][nowsy].second;
	MAP[nowsx][nowsy].first = 0;MAP[nowsx][nowsy].second = 0;
	moveFish(nowsx, nowsy);

	for (int i = 1;i < 4;i++) {
		int tsx = dx[nowdir] * i + nowsx;
		int tsy = dy[nowdir] * i + nowsy;
		if (tsx < 0 || tsy < 0 || tsx >= 4 || tsy >= 4)continue;
		if (MAP[tsx][tsy].first != 0)
			dfs(tsx, tsy, nowdir, res);
	}
	res -= tmp;
	MAP[nowsx][nowsy].first = tmp;
	MAP[nowsx][nowsy].second = nowdir;
	memcpy(MAP, tempArr, sizeof(MAP));

}
void solve()
{
	int res = 0;
	dfs(sx, sy, sdir, res);
	cout << maxValue;
}
int main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			cin >> MAP[i][j].first;
			cin >> MAP[i][j].second;
		}
	}
	sx = 0, sy = 0, sdir = MAP[0][0].second;
	solve();
}