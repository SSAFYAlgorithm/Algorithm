#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>>chicken;
vector<pair<int, int>>findNow;
int MAP[51][51];
int N, M;
int minChicken = 21e4;
int calc(int r, int c)
{
	int now = 10000;
	for (int i = 0;i < M;i++) {
		if (abs(r - findNow[i].first) + abs(c - findNow[i].second) < now) {
			now = abs(r - findNow[i].first) + abs(c - findNow[i].second);
		}
	}
	return now;
}
int find()
{
	int sum = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (MAP[i][j] == 1) {
				sum += calc(i, j);
			}
		}

	}
	return sum;
}
int solve()
{
	int minNum = 21e6;
	vector<int>flag;
	for (int i = 0;i < M;i++) {
		flag.push_back(1);
	}
	int k = chicken.size();
	for (int i = 0;i < k - M;i++) {
		flag.push_back(0);
	}
	sort(flag.begin(), flag.end());
	do {
		for (int i = 0;i < k;i++) {
			if (flag[i] == 1) {
				findNow.push_back(chicken[i]);
			}
		}
		int now = find();
		if (now < minNum) minNum = now;
		findNow.clear();
	} while (next_permutation(flag.begin(), flag.end()));

	return minNum;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				chicken.push_back(pair<int, int>(i, j));
			}
		}
	}
	cout << solve();
}
