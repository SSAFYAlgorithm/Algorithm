#include<iostream>
#include<string.h>
using namespace std;
int N;
int score[51][9];
int res[9];
int visited[9];
int player[8] = { 1,2,3,4,5,6,7,8 };
int nowres[9];
int calc()
{
	int sum = 0;
	int taza = 0;
	memcpy(nowres, res, sizeof(nowres));
	for (int i = 8;i >= 3;i--) {
		nowres[i + 1] = nowres[i];
	}
	nowres[3] = 0;
	int arr[10] = { 0 };//0,1,2,3


	for (int i = 0;i < N;i++) {
		int out = 0;

		while (1)
		{
			int now = nowres[taza];
			arr[0] = 1;
			if (score[i][now] == 1) {
				for (int j = 3;j >= 0;j--) {
					if (arr[j]) {
						arr[j + 1] = 1;
						arr[j] = 0;
					}
				}
			}
			else if (score[i][now] == 2) {
				for (int j = 3;j >= 0;j--) {
					if (arr[j]) {
						arr[j + 2] = 1;
						arr[j] = 0;
					}
				}
			}
			else if (score[i][now] == 3) {
				for (int j = 3;j >= 0;j--) {
					if (arr[j]) {
						arr[j + 3] = 1;
						arr[j] = 0;
					}
				}
			}
			else if (score[i][now] == 4) {
				for (int j = 3;j >= 0;j--) {
					if (arr[j]) {
						arr[j + 4] = 1;
						arr[j] = 0;
					}
				}
			}
			else if (score[i][now] == 0) {
				out++;
			}
			if (out >= 3) {
				memset(arr, 0, sizeof(arr));
				taza++;
				if (taza >= 9)taza = 0;
				break;
			}
			for (int j = 4;j < 9;j++) {
				if (arr[j]) {
					sum++; arr[j] = 0;
				}
			}
			taza++;
			if (taza >= 9)taza = 0;
		}
	}
	return sum;
}
int maxValue = -1;
void dfs(int level)
{
	if (level == 8) {

		int now = calc();
		if (now > maxValue)
			maxValue = now;
		return;
	}
	for (int i = 0;i < 8;i++) {
		if (visited[i])continue;

		visited[i] = 1;
		res[level] = player[i];
		dfs(level + 1);
		visited[i] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> score[i][j];
		}
	}
	dfs(0);
	cout << maxValue;
}