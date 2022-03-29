#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int res[21][21] = { 0 };
int now;
int fr[401][4] = { 0 };
int frist[21][21] = { 0 };

bool cmp(pair<int, int>left, pair<int, int>right) {
	if (left.first < right.first)return true;
	if (left.first > right.first)return false;
	return left.second < right.second;
}
void place()
{

	int arr[21][21] = { 0 };
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	int cnt;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (res[i][j])continue;
			cnt = 0;
			for (int k = 0;k < 4;k++) {
				int tx = i + dx[k];
				int ty = j + dy[k];
				if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
				for (int l = 0;l < 4;l++) {
					if (fr[now][l] == res[tx][ty])
						cnt++;
				}
			}
			arr[i][j] = cnt;
		}
	}
	int max1 = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (max1 < arr[i][j]) {
				max1 = arr[i][j];
			}
		}
	}
	vector<pair<int, int>>firstVect;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (res[i][j])continue;
			if (arr[i][j] == max1) {
				firstVect.push_back(pair<int, int>(i, j));
			}
		}
	}
	if (firstVect.size() == 1) {
		res[firstVect[0].first][firstVect[0].second] = now;
		return;
	}



	int secondArr[21][21] = { 0 };
	int cnt2;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (res[i][j])continue;
			if (arr[i][j] == max1) {
				cnt2 = 0;
				for (int k = 0;k < 4;k++) {
					int tx = dx[k] + i;
					int ty = dy[k] + j;
					if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
					if (res[tx][ty] == 0) {
						cnt2++;
					}
				}
				secondArr[i][j] = cnt2;
			}
		}
	}
	int max2 = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (secondArr[i][j] > max2) {
				max2 = secondArr[i][j];
			}
		}
	}
	vector<pair<int, int>>secondVect;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (res[i][j])continue;
			if (secondArr[i][j] == max2) {
				secondVect.push_back(pair<int, int>(i, j));
			}
		}
	}
	if (secondVect.size() == 1) {
		res[secondVect[0].first][secondVect[0].second] = now;
		return;
	}
	sort(secondVect.begin(), secondVect.end(), cmp);
	res[secondVect[0].first][secondVect[0].second] = now;
}
int calculate()
{
	int sum = 0;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int cnt = 0;
			for (int k = 0;k < 4;k++) {
				int tx = dx[k] + i;
				int ty = dy[k] + j;
				if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
				for (int l = 0;l < 4;l++) {
					if (res[tx][ty] == fr[res[i][j]][l]) {
						cnt++;
					}
				}
			}
			if (cnt == 4)sum += 1000;
			else if (cnt == 3)sum += 100;
			else if (cnt == 2)sum += 10;
			else if (cnt == 1)sum += 1;
		}
	}
	return sum;
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0;i < N * N;i++) {
		cin >> now;
		for (int j = 0;j < 4;j++) {
			cin >> fr[now][j];
		}
		place();

	}
	cout << calculate();
}