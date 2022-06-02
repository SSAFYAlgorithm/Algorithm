#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int r, c, k;
int R, C;
int MAP[101][101];
int temp[101][101];
bool cmp(pair<int, int>left, pair<int, int>right) {
	if (left.second < right.second)return 1;
	if (left.second > right.second)return 0;
	return left.first < right.first;
}
void sortR()
{
	int size = 0;
	for (int i = 0;i < R;i++) {
		int dat[101] = { 0 };
		for (int j = 0;j < C;j++) {
			if (!MAP[i][j])continue;
			dat[MAP[i][j]]++;
		}
		vector<pair<int, int>>vect;
		for (int j = 1;j < 101;j++) {
			if (!dat[j])continue;
			vect.push_back(make_pair(j, dat[j]));//index,value
		}
		sort(vect.begin(), vect.end(), cmp);
		int t = 0;
		for (int j = 0;j < vect.size();j++) {
			if (t >= 100)break;
			temp[i][t++] = vect[j].first;
			temp[i][t++] = vect[j].second;
		}
		if (size < t)size = t;
	}
	C = size;
}
void sortC()
{
	int size = 0;
	for (int i = 0;i < C;i++) {
		int dat[101] = { 0 };
		for (int j = 0;j < R;j++) {
			if (!MAP[j][i])continue;
			dat[MAP[j][i]]++;
		}
		vector<pair<int, int>>vect;
		for (int j = 1;j < 101;j++) {
			if (!dat[j])continue;
			vect.push_back(make_pair(j, dat[j]));
		}
		sort(vect.begin(), vect.end(), cmp);
		int t = 0;
		for (int j = 0;j < vect.size();j++) {
			if (t >= 100)break;
			temp[t++][i] = vect[j].first;
			temp[t++][i] = vect[j].second;
		}
		if (size < t)size = t;
	}
	R = size;
}
int solve()
{

	for (int t = 0;t <= 100;t++) {
		if (MAP[r - 1][c - 1] == k) {
			cout << t;
			return 0;
		}
		if (R >= C)sortR();
		else sortC();
		memcpy(MAP, temp, sizeof(MAP));
		memset(temp, 0, sizeof(temp));
	}
	cout << -1;
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	R = 3, C = 3;
	cin >> r >> c >> k;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> MAP[i][j];
		}
	}
	solve();
}