#include<iostream>
#include<queue>
using namespace std;

int n, m, h;
int arr[100][100][100];
int len[100][100][100];
int dz[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };
int dx[6] = { 0,0,1,-1,0,0 };

struct T {
	int z, y, x;
};

queue<T> q;
queue<T> sq; //start
int zero_cnt = 0;

void bfs(int nowz, int nowy, int nowx) {
	while (1) {
		if (q.empty()) {
			break;
		}
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		for (int i = 0; i < 6; i++) {
			int hs = z + dz[i];
			int r = y + dy[i];
			int c = x + dx[i];
			if (r >= 0 && r < n && c >= 0 && c < m && hs>=0 && hs<h) {
				if (!len[hs][r][c] && arr[hs][r][c] != -1) {
					q.push({ hs, r, c });
					len[hs][r][c] = len[z][y][x] + 1;
					zero_cnt--;
				}
			}
		}

		q.pop();
	}
	return;
}

int main() {
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 0) zero_cnt++;
				if (arr[k][i][j] == 1) {
					q.push({ k,i,j });
					sq.push({ k,i,j });
				}
			}
		}
	}


	if (!zero_cnt) {
		cout << 0;
		return 0;
	}

	while (!sq.empty()) {
		len[sq.front().z][sq.front().y][sq.front().x] = 1;
		sq.pop();
	}

	int nowz = q.front().z;
	int nowy = q.front().y;
	int nowx = q.front().x;
	bfs(nowz, nowy, nowx);

	if (zero_cnt) {
		cout << -1;
		return 0;
	}

	int max = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (max < len[k][i][j]) {
					max = len[k][i][j];
				}
			}
		}
	}

	cout << max - 1;

	return 0;
}