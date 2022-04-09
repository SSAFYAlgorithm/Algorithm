#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int N, M;
int MAP[9][9];
int temp[9][9];
vector<pair<int, int>>pos;
queue<pair<int, int>>que;
queue<pair<int, int>>queTemp;
vector<pair<int, int>>nowWall;
int findBfs()
{
	memcpy(temp, MAP, sizeof(temp));
	for (int i = 0;i < 3;i++) {
		int r = nowWall[i].first;
		int c = nowWall[i].second;
		temp[r][c] = 1;
	}
	queTemp = que;
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	while (!queTemp.empty()) {
		pair<int, int>now = queTemp.front();queTemp.pop();
		for (int i = 0;i < 4;i++) {
			int tx = dx[i] + now.first;
			int ty = dy[i] + now.second;
			if (tx < 0 || ty < 0 || tx >= N || ty >= M)continue;
			if (temp[tx][ty])continue;
			temp[tx][ty] = 2;
			queTemp.push(pair<int, int>(tx, ty));
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

int maxValue = -1;
void combination()
{
	vector<int>flag;

	for (int i = 0;i < pos.size() - 3;i++) {
		flag.push_back(0);
	}
	for (int i = 0;i < 3;i++) {
		flag.push_back(1);
	}

	do {
		for (int i = 0;i < flag.size();i++) {
			if (flag[i] == 1) {
				nowWall.push_back(pos[i]);
			}
		}

		int now = findBfs();
		if (maxValue < now)maxValue = now;
		nowWall.clear();
	} while (next_permutation(flag.begin(), flag.end()));

}
void solve()
{
	combination();
	cout << maxValue;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				que.push(pair<int, int>(i, j));
			}
			if (MAP[i][j] == 0) {
				pos.push_back(pair<int, int>(i, j));
			}
		}
	}
	solve();
}