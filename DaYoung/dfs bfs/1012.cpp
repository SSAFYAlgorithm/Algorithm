#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
// 가로세로 바뀐 것 같지만 상관엑스,,
int t, m, n, k;
int map[51][51] = { 0 };
int checked[51][51]={0};
queue<pair<int,int>> q;
int dr[8] = { -1,0,0,1 };
int dc[8] = { 0,-1,1,0 };
int cnt;

void bfs(int y, int  x) {
	checked[y][x] = 1;
	cnt++;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int b = q.front().first;
		int a = q.front().second;

		for (int i = 0; i < 4; i++) {
			int r = b + dr[i];
			int c = a + dc[i];
			if (r >= 0 && r < m && c >= 0 && c < n) {
				if (checked[r][c] != 1 && map[r][c] == 1) {
					checked[r][c] = 1;
					q.push(make_pair(r, c));
				}
			}
		}
		q.pop();
	}
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(map, 0, sizeof(map));
		memset(checked, 0, sizeof(checked));
		cnt = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int y, x;
			cin >> y >> x;
			map[y][x] = 1;
		}
		// bfs
		for (int b = 0; b < m; b++) {
			for (int a = 0; a < n; a++) {
				if (checked[b][a] != 1 && map[b][a] == 1) {
					bfs(b, a);
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}