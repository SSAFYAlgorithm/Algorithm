#include<iostream>

using namespace std;

int N;
int arr[21][21];
int team[21];
int startSum = 0;
int linkSum = 0;
int resStart[2];
int resLink[2];
void startDfs(int level, int next) {
	if (level == 2) {
		startSum += arr[resStart[0]][resStart[1]];
		startSum += arr[resStart[1]][resStart[0]];
		return;
	}
	for (int i = next;i < N;i++) {
		if (!team[i]) continue;
		resStart[level] = i;
		startDfs(level + 1, i + 1);
	}
}
void linkDfs(int level, int next) {
	if (level == 2) {
		linkSum += arr[resLink[0]][resLink[1]];
		linkSum += arr[resLink[1]][resLink[0]];
		return;
	}
	for (int i = next;i < N;i++) {
		if (team[i]) continue;
		resLink[level] = i;
		linkDfs(level + 1, i + 1);
	}
}
int teamfight()
{
	startSum = 0;
	linkSum = 0;
	startDfs(0, 0);
	linkDfs(0, 0);
	int d = abs(startSum - linkSum);
	return d;
}
int M = 21e7;
void dfs(int level, int next)
{
	if (level == N / 2) {
		int now = teamfight();
		if (M > now) {
			M = now;
		}
		return;
	}
	for (int i = next;i < N;i++) {
		if (team[i])continue;
		team[i] = 1;
		dfs(level + 1, i + 1);
		team[i] = 0;

	}
}
void solve()
{
	dfs(0, 0);
}
int main()
{
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	cout << M;
}