#include<iostream>
#include<string.h>
using namespace std;
int N;
int MAP[21][21];
int temp[21][21];
int res[5];
void up()
{
	for (int c = 0;c < N;c++) {
		int index = 0;
		int t = 0;
		for (int r = 0;r < N;) {
			t++;
			if (t > 3 * N)break;
			if (!temp[r][c]) {
				r++;
				continue;
			}
			else {
				int exist = temp[r][c];
				temp[r][c] = 0;
				temp[index][c] = exist;
				for (int i = index + 1;i < N;i++) {
					if (temp[i][c] == temp[index][c]) {
						temp[index][c] *= 2;
						temp[i][c] = 0;
						index++;
						r = index + 1;
						break;
					}
					else if (temp[i][c] && temp[index][c] != temp[i][c]) {
						int n = temp[i][c];
						temp[i][c] = 0;
						temp[++index][c] = n;
						r = index;
						break;
					}
				}

			}
		}
	}
}
void left()
{
	for (int r = 0;r < N;r++) {
		int index = 0;
		int t = 0;
		for (int c = 0;c < N;) {
			t++;
			if (t > 3 * N)break;
			if (!temp[r][c]) {
				c++; continue;
			}
			else {
				int exist = temp[r][c];
				temp[r][c] = 0;
				temp[r][index] = exist;
				for (int i = index + 1;i < N;i++) {
					if (temp[r][i] == temp[r][index]) {
						temp[r][index] *= 2;
						temp[r][i] = 0;
						index++;
						c = index + 1;
						break;
					}
					else if (temp[r][i] && temp[r][index] != temp[r][i]) {
						int n = temp[r][i];
						temp[r][i] = 0;
						temp[r][++index] = n;
						c = index;
						break;
					}
				}

			}
		}
	}
}
void down()
{
	for (int c = 0;c < N;c++) {
		int index = N - 1;
		int t = 0;
		for (int r = N - 1;r >= 0;) {
			t++;
			if (t > 3 * N)break;
			if (!temp[r][c]) {
				r--;
				continue;
			}
			else {
				int exist = temp[r][c];
				temp[r][c] = 0;
				temp[index][c] = exist;
				for (int i = index - 1;i >= 0;i--) {
					if (temp[i][c] == temp[index][c]) {
						temp[index][c] *= 2;
						temp[i][c] = 0;
						index--;
						r = index - 1;
						break;
					}
					else if (temp[i][c] && temp[index][c] != temp[i][c]) {
						int n = temp[i][c];
						temp[i][c] = 0;
						temp[--index][c] = n;
						r = index;
						break;
					}
				}
			}
		}
	}
}
void right()
{
	for (int r = 0;r < N;r++) {
		int index = N - 1;
		int t = 0;
		for (int c = N - 1;c >= 0;) {
			t++;
			if (t > 3 * N)break;
			if (!temp[r][c]) {
				c--; continue;
			}
			else {
				int exist = temp[r][c];
				temp[r][c] = 0;
				temp[r][index] = exist;
				for (int i = index - 1;i >= 0;i--) {
					if (temp[r][i] == temp[r][index]) {
						temp[r][index] *= 2;
						temp[r][i] = 0;
						index--;
						c = index - 1;
						break;
					}
					else if (temp[r][i] && temp[r][index] != temp[r][i]) {
						int n = temp[r][i];
						temp[r][i] = 0;
						temp[r][--index] = n;
						c = index;
						break;
					}
				}

			}
		}
	}
}
int calc()
{
	memcpy(temp, MAP, sizeof(temp));
	for (int i = 0;i < 5;i++) {
		if (res[i] == 0) {//up
			up();
		}
		else if (res[i] == 1) {
			left();
		}
		else if (res[i] == 2) {
			down();
		}
		else if (res[i] == 3) {
			right();
		}
	}
	int maxValue = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (maxValue < temp[i][j]) {
				maxValue = temp[i][j];
			}
		}
	}
	return maxValue;
}
int maxV = -1;
void dfs(int level)
{
	if (level == 5) {
		int now = calc();
		if (maxV < now) {
			maxV = now;
		}
		return;
	}
	for (int i = 0;i < 4;i++) {
		res[level] = i;
		dfs(level + 1);
	}
}

int solve()
{
	dfs(0);
	return maxV;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
		}
	}
	cout << solve();
}