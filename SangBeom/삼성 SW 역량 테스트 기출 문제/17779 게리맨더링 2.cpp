#include<iostream>
#include<algorithm>
#define MAXSIZE 21
using namespace std;
int MAP[MAXSIZE][MAXSIZE];
int N;
int calc(int x, int y, int d1, int d2) {
	pair<int, int>top;	top.first = x;top.second = y;
	pair<int, int>left; left.first = x + d1; left.second = y - d1;
	pair<int, int>right; right.first = x + d2; right.second = y + d2;
	pair<int, int>bottom; bottom.first = x + d1 + d2;bottom.second = y - d1 + d2;
	if (left.second < 0 || right.second >= N || bottom.first >= N) return -1;
	int temp[MAXSIZE][MAXSIZE] = { 0 };
	for (int i = 0;i < left.first;i++) {
		for (int j = 0;j <= top.second;j++) {
			temp[i][j] = 1;
		}
	}
	for (int i = 0;i <= right.first;i++) {
		for (int j = top.second + 1;j < N;j++) {
			temp[i][j] = 2;
		}
	}
	for (int i = left.first;i < N;i++) {
		for (int j = 0;j < bottom.second;j++) {
			temp[i][j] = 3;
		}
	}
	for (int i = right.first + 1;i < N;i++) {
		for (int j = bottom.second;j < N;j++) {
			temp[i][j] = 4;
		}
	}
	for (int i = top.first;i <= bottom.first;i++) {
		for (int j = left.second;j <= right.second;j++) {
			if (i + j < top.first + top.second)continue;
			if (i + j > bottom.first + bottom.second)continue;
			if (j - i > top.second - top.first)continue;
			if (i - j > bottom.first - bottom.second)continue;
			temp[i][j] = 5;
		}
	}
	int sector[6] = { -1,0, };

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			sector[temp[i][j]] += MAP[i][j];
		}
	}
	sort(sector, sector + 6);
	return sector[5] - sector[1];
}
void solve()
{
	int min = 21e4;
	for (int x = 0;x < N;x++) {
		for (int y = 0;y < N;y++) {
			for (int d1 = 1;d1 <= N;d1++) {
				for (int d2 = 1;d2 <= N;d2++) {
					int now = calc(x, y, d1, d2);
					if (now == -1)continue;
					if (now < min)min = now;
				}
			}
		}
	}
	cout << min;
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
	solve();

}