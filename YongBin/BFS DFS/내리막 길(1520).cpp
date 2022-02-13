#include <iostream>

using namespace std;

int arr[500][500];
int dp[500][500];

int n, m;
int result = 0;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		return 1;
	}
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] < arr[x][y]) {
			dp[x][y] = dp[x][y] + dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	result = dfs(0, 0);
	cout << result;
	return 0;
}