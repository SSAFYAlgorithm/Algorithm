#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n;
string s[25];
int checked[26][26]={0};
queue<pair<int,int>> q;
priority_queue<int, vector<int>, greater<int>> pq;
int dr[8] = { -1,0,0,1 };
int dc[8] = { 0,-1,1,0 };

void bfs(int y, int  x) {
	checked[y][x] = 1;
	int cnt = 0;
	cnt++;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int b = q.front().first;
		int a = q.front().second;

		for (int i = 0; i < 4; i++) {
			int r = b + dr[i];
			int c = a + dc[i];
			if (r >= 0 && r < n && c >= 0 && c < n) {
				if (checked[r][c] != 1 && s[r][c] == '1') {
					checked[r][c] = 1;
					cnt++;
					q.push(make_pair(r, c));
				}
			}
		}
		q.pop();
	}
	pq.push(cnt);

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (checked[i][j] != 1 && s[i][j] == '1') {
				bfs(i, j);
			}
		}
	}
	cout<<pq.size() << "\n";
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	return 0;

}