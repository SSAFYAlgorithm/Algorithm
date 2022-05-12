#include<iostream>
#include<string.h>
#define MAXSIZE 6
using namespace std;

int MAP[MAXSIZE][MAXSIZE];
int tmpMap[MAXSIZE][MAXSIZE];
int castle[MAXSIZE];
int N, M, D;
int sum;
void enemyMove() {
	for (int i = N - 1;i >= 1;i--) {
		for (int j = 0;j < M;j++) {
			MAP[i][j] = MAP[i - 1][j];
		}
	}
	for (int i = 0;i < M;i++) {
		MAP[0][i] = 0;
	}
}
int check()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (MAP[i][j])return 1;
		}
	}
	return 0;
}
void killenemy()
{
	int tmp[MAXSIZE][MAXSIZE] = { 0 };

	for (int t = 0;t < N;t++) {
		if (castle[t]) {
			int r = -1, c = M + 1;
			int flag = 0;
			int distance = D + 1;
			for (int j = 0;j < M;j++) {
				for (int i = N - 1;i >= 0;i--) {
					if (!MAP[i][j])continue;
					if (abs(i - N) + abs(j - t) <= D) {
						int nowd = abs(i - N) + abs(j - t);
						if (nowd < distance) {
							r = i;c = j;
							distance = nowd;
							flag = 1;
						}
						else if (nowd == distance) {
							if (c > j) {
								r = i;c = j;
								flag = 1;
							}
						}
					}
				}

			}
			if (flag) {
				tmp[r][c] = 1;
			}

		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (tmp[i][j]) {
				sum++;
				MAP[i][j] = 0;
			}
		}
	}
}
int calc()
{
	sum = 0;
	while (1)
	{
		killenemy();
		enemyMove();
		int now = check();
		if (!now)break;
	}
	return sum;
}
int maxValue = -1;
void dfs(int level, int next)
{
	if (level == 3) {
		memcpy(MAP, tmpMap, sizeof(MAP));
		int now = calc();
		if (now > maxValue)
		{
			maxValue = now;
		}
		return;
	}
	for (int i = next;i < M;i++) {
		if (castle[i])continue;
		castle[i] = 1;
		dfs(level + 1, i + 1);
		castle[i] = 0;

	}
}
int ans = 0;


void solve()
{
	memcpy(tmpMap, MAP, sizeof(tmpMap));
	dfs(0, 0);
	cout << maxValue;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> D;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> MAP[i][j];
		}
	}
	solve();
}