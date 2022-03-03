#include<iostream>
#include<string>
#include<queue>
using namespace std;

int n, m;
string str[100];
int len[100][100];
int dr[4] = { 0,1,-1,0 };
int dc[4] = { 1,0,0,-1 };
queue<pair<int, int>> q;

void bfs(int nowy, int nowx) {
	int y = nowy;
	int x = nowx;
	while (1) {
		if (q.empty()) {
			break;
		}
		y = q.front().first;
		x = q.front().second;
		for (int i = 0; i < 4; i++) {
			int r = y + dr[i];
			int c = x + dc[i];
			if (r >= 0 && r < n && c >= 0 && c < m) {
				if (!len[r][c] && str[r][c]=='1') {
					q.push(make_pair(r, c));
					len[r][c] = len[y][x]+1;
				}
			}
		}

		q.pop();
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	len[0][0] = 1;
	q.push(make_pair(0, 0));
	bfs(0,0);
	cout << len[n-1][m-1];
	return 0;
}