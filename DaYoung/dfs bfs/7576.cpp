#include<iostream>
#include<queue>
using namespace std;

int n, m;
int arr[1000][1000];
int len[1000][1000];
int dr[4] = { 0,1,-1,0 };
int dc[4] = { 1,0,0,-1 };
queue<pair<int, int>> q;
queue<pair<int, int>> sq;
int zero_cnt = 0;

void bfs(int nowy, int nowx) {
	while (1) {
		if (q.empty()) {
			break;
		}
		int y = q.front().first;
		int x = q.front().second;
		for (int i = 0; i < 4; i++) {
			int r = y + dr[i];
			int c = x + dc[i];
			if (r >= 0 && r < n && c >= 0 && c < m) {
				if (!len[r][c]&&arr[r][c]!=-1) {
					q.push(make_pair(r, c));
					len[r][c] = len[y][x]+1;
					zero_cnt--;
				}
			}
		}

		q.pop();
	}
	return;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) zero_cnt++;
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				sq.push(make_pair(i, j));
			}
		}
	}

	if (!zero_cnt) {
		cout << 0;
		return 0;
	}

	while (!sq.empty()) {
		len[sq.front().first][sq.front().second] = 1;
		sq.pop();
	}

	int nowy = q.front().first;
	int nowx = q.front().second;
	bfs(nowy, nowx);

	if (zero_cnt) {
		cout << -1;
		return 0;
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < len[i][j]) {
				max = len[i][j];
			}
		}
	}

	cout << max-1;

	return 0;
}