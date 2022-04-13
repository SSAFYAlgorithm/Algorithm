#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int arr[550][550];
int used[550][550];
int dy[3] = { 1,0,0 };
int dx[3] = { 0,1,-1 };
int dyT[4] = { 1,0,0,-1 };
int dxT[4] = { 0,1,-1,0 };
int res = 0;

// T모양 제외는 모두 검사
void dfs(int y, int x, int cnt, int SUM) {
	if (cnt == 4) {
		if (SUM > res) {
			res = SUM;
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (used[ny][nx] != 0) continue;
		used[ny][nx] = 1;
		dfs(ny, nx, cnt + 1, SUM + arr[ny][nx]);
		used[ny][nx] = 0;
	}
}

// T모양도 검사필요
int dfsT(int y, int x, int cnt, int lastdir) {
	if (cnt == 3) {	
		return arr[y][x];
	}
	int ans = 0;
	if (cnt < 2) {
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dyT[i];
			int nx = x + dxT[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			ans = max(ans,dfsT(ny, nx, cnt + 1, i)+arr[y][x]);
		}
	}
	else {
		// 3가지 경우로
		int temp1 = 0;
		int temp2 = 0;
		int temp3 = 0;
		if (lastdir == 0) { // 위에서 내려오는 경우
			// case 1;
			if (x - 1 >= 0 && x+1 < M) {
				temp1 = dfsT(y, x - 1, cnt + 1, 2) + dfsT(y, x + 1, cnt + 1, 1);
			}
			// case 2;
			if (x - 1 >= 0 && y + 1 < N) {
				temp2 = dfsT(y, x - 1, cnt + 1, 2) + dfsT(y + 1, x, cnt + 1, 0);
			}

			// case 3;
			if (x + 1 < M && y + 1 < N) {
				temp3 = dfsT(y, x + 1, cnt + 1, 1) + dfsT(y + 1, x, cnt + 1, 0);
			}
		}
		else if (lastdir == 1) { // 왼쪽에서 오른쪽으로 가는 경우
			// case 1;
			if (y - 1 >= 0 && y + 1 < N) {
				temp1 = dfsT(y - 1, x, cnt + 1, -1) + dfsT(y + 1, x, cnt + 1, -1);
			}
			// case 2;
			if (y - 1 >= 0 && x + 1 < M) {
				temp2 = dfsT(y - 1, x, cnt + 1, -1) + dfsT(y, x + 1, cnt + 1, -1);
			}

			// case 3;
			if (y + 1 < N && x + 1 < M) {
				temp3 = dfsT(y + 1, x, cnt + 1, -1) + dfsT(y, x + 1, cnt + 1, -1);
			}
		}

		else if (lastdir == 2) { // 오른쪽에서 왼쪽으로 가는 경우
			// case 1;
			if (y - 1 >= 0 && y + 1 < N) {
				temp1 = dfsT(y - 1, x, cnt + 1, -1) + dfsT(y + 1, x, cnt + 1, -1);
			}
			//// case 2;
			//if (y - 1 >= 0 && x - 1 >= 0) {
			//	temp2 = dfsT(y - 1, x, cnt + 1, -1) + dfsT(y, x - 1, cnt + 1, -1);
			//}

			//// case 3;
			//if (y + 1 < N && x - 1 >= 0) {
			//	temp3 = dfsT(y + 1, x, cnt + 1, -1) + dfsT(y, x - 1, cnt + 1, -1);
			//}
		}

		else if (lastdir == 3) {
			if (x - 1 >= 0 && x + 1 < M) {
				temp1 = dfsT(y, x - 1, cnt + 1, -1) + dfsT(y, x + 1, cnt + 1, -1);
			}
		}
		return max({ temp1,temp2,temp3 }) + arr[y][x];
	}
	return ans;
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			used[y][x] = 1;
			dfs(y, x, 1, arr[y][x]);
			used[y][x] = 0;
			int resT = dfsT(y, x, 1, -1);
			if (resT > res) {
				res = resT;
			}
		}
	}

	cout << res;


	return 0;
}