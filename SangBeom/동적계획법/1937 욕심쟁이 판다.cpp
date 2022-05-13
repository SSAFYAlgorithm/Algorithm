#include<iostream>
#include<string.h>
#include<cmath>
#define MAXINDEX 501
using namespace std;

int MAP[MAXINDEX][MAXINDEX];
int dp[MAXINDEX][MAXINDEX];
int N;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };


int dfs(int r, int c)
{

	if (dp[r][c] != -1) {
		return dp[r][c];
	}
	dp[r][c] = 1;
	for (int i = 0;i < 4;i++) {
		int tx = r + dx[i];
		int ty = c + dy[i];
		if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;

		if (MAP[r][c] < MAP[tx][ty]) {
			dp[r][c] = max(dp[r][c], dfs(tx, ty) + 1);
		}
	}
	return dp[r][c];
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];

		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			dfs(i, j);
		}
	}
	int ans = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (dp[i][j] > ans)ans = dp[i][j];
		}
	}
	cout << ans;

}