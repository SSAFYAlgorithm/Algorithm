#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
struct Node {
	int r;
	int c;
	int s;
};
vector<Node>vect;
int N, M;
int K;
int arr[51][51];
int temp[51][51];
int res[6];
int visited[6];
void rotate(int r, int c, int s)
{
	int temp2[51][51] = { 0 };
	temp2[r][c] = temp[r][c];
	int dr[4] = { 0,1,0,-1 };
	int dc[4] = { 1,0,-1,0 };
	int nows = s;
	while (nows) {
		int sr = r - nows;
		int sc = c - nows;
		for (int d = 0;d < 4;d++) {
			int tr;
			int tc;
			for (int i = 1;i < 2 * nows + 1;i++) {
				tr = dr[d] * i + sr;
				tc = dc[d] * i + sc;
				temp2[tr][tc] = temp[tr - dr[d]][tc - dc[d]];
			}
			sr = tr;
			sc = tc;
		}
		nows--;
	}
	for (int i = r - s;i <= r + s;i++) {
		for (int j = c - s;j <= c + s;j++) {
			temp[i][j] = temp2[i][j];
		}
	}
}
int calc()
{
	memcpy(temp, arr, sizeof(temp));
	for (int i = 0;i < K;i++) {
		int now;
		for (int k = 0;k < 6;k++) {
			if (res[k] == i) {
				now = k;
				break;
			}
		}
		int r = vect[now].r;
		int c = vect[now].c;
		int s = vect[now].s;
		rotate(r, c, s);
	}
	int minSum = 21e6;
	for (int i = 0;i < N;i++) {
		int rSum = 0;
		for (int j = 0;j < M;j++) {
			rSum += temp[i][j];
		}
		if (rSum < minSum)minSum = rSum;
	}
	return minSum;
}
int minS = 21e6;
void dfs(int level)
{
	if (level == K) {
		int now = calc();
		if (minS > now) {
			minS = now;
		}
		return;
	}
	for (int i = 0;i < K;i++) {
		if (visited[i])continue;
		visited[i] = 1;
		res[level] = i;
		dfs(level + 1);
		visited[i] = 0;
	}
}

int solve()
{
	dfs(0);
	return minS;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	cin >> K;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0;i < K;i++) {
		int r, c, s;
		cin >> r >> c >> s;
		vect.push_back({ r - 1,c - 1,s });
	}
	cout << solve();
}