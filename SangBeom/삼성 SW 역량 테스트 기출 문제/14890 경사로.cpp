#include<iostream>

using namespace std;
int N, L;
int MAP[101][101];
int garo[101][101];
int sero[101][101];
int ans;
void setGaro(int r)
{
	for (int i = 0;i < N - 1;i++) {
		if (MAP[r][i] == MAP[r][i + 1])continue;
		if (abs(MAP[r][i] - MAP[r][i + 1]) >= 2)return;

		if (MAP[r][i] == MAP[r][i + 1] - 1) {
			for (int j = i; j > i - L;j--) {
				if (j < 0)return;
				if (garo[r][j])return;
				garo[r][j] = 1;
			}
		}
		if (MAP[r][i] == MAP[r][i + 1] + 1) {
			for (int j = i + 1;j < i + 1 + L;j++) {
				if (j >= N)return;
				if (garo[r][j])return;
				garo[r][j] = 1;
			}
		}
	}
	ans++;
}
void setSero(int c) {
	for (int i = 0;i < N - 1;i++) {
		if (MAP[i][c] == MAP[i + 1][c])continue;
		if (abs(MAP[i][c] - MAP[i + 1][c]) >= 2)return;

		if (MAP[i][c] == MAP[i + 1][c] - 1) {
			for (int j = i; j > i - L;j--) {
				if (j < 0)return;
				if (sero[j][c])return;
				sero[j][c] = 1;
			}
		}
		if (MAP[i][c] == MAP[i + 1][c] + 1) {
			for (int j = i + 1;j < i + 1 + L;j++) {
				if (j >= N)return;
				if (sero[j][c])return;
				sero[j][c] = 1;
			}
		}
	}
	ans++;
}
void solve()
{
	for (int i = 0;i < N;i++) {
		setGaro(i);
		setSero(i);
	}
	cout << ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> L;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
		}
	}
	solve();
}