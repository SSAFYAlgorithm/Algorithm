#include <iostream>
using namespace std;

int M, N;
int arr[501][501];
int dp[501][501];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int DFS(int y, int x) {
	if (y == M - 1 && x == N - 1) {
		dp[y][x] = 1;
		return 1;
	}
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (arr[ny][nx] >= arr[y][x]) continue;
		dp[y][x] += DFS(ny, nx);
	}
	return dp[y][x];
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	
	cout << DFS(0, 0);



	return 0;
}