#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int N, M, K;
int gnd[11][11];
int MAP[11][11];
int die[11][11];
vector<vector<deque<int>>>tree;
void spring()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int index = -1;
			for (int k = 0;k < tree[i][j].size();k++) {
				int now = tree[i][j][k];
				if (now <= gnd[i][j]) {
					gnd[i][j] -= now;
					tree[i][j][k]++;
				}
				else {
					index = k;
					break;
				}
			}
			if (index == -1)continue;
			int nowSize = tree[i][j].size();
			for (int k = 0; k < nowSize - index;k++) {
				die[i][j] += (tree[i][j].back() / 2);
				tree[i][j].pop_back();
			}
		}
	}
}
void summer()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			gnd[i][j] += die[i][j];
			die[i][j] = 0;
		}
	}
}
void fall()
{
	int dx[8] = { -1,-1,-1,0,0,1,1,1 };
	int dy[8] = { -1,0,1,-1,1,-1,0,1 };
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!tree[i][j].size())continue;
			for (int k = 0;k < tree[i][j].size();k++) {
				if (tree[i][j][k] % 5)continue;
				for (int l = 0;l < 8;l++) {
					int tx = dx[l] + i;
					int ty = dy[l] + j;
					if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
					tree[tx][ty].push_front(1);
				}
			}
		}
	}
}
void winter()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			gnd[i][j] += MAP[i][j];
		}
	}
}
void solve()
{
	for (int t = 0; t < K;t++) {
		spring();
		summer();
		fall();
		winter();
	}
	int ans = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++) {
		tree.push_back(vector<deque<int>>());
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
			gnd[i][j] = 5;
			tree[i].push_back(deque<int>());
		}
	}
	for (int i = 0;i < M;i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}
	solve();
}