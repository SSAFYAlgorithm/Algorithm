#include<iostream>
#include<string.h>
#define MAXINDEX 101
using namespace std;
int N;
int sr; int sc; int er; int ec;
int dx[4] = { 1,0,-1,0 };//¿ì»óÁÂÇÏ
int dy[4] = { 0,-1,0,1 };
int MAP[MAXINDEX][MAXINDEX][20];
int tmp[MAXINDEX][MAXINDEX];
void rotate(int cnt)
{
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0;i < MAXINDEX;i++) {
		for (int j = 0;j < MAXINDEX;j++) {
			tmp[j][MAXINDEX - 1 - i] = MAP[i][j][cnt];
		}
	}

	int tr = ec; int tc = MAXINDEX - 1 - er;
	int kr = tr - er; int kc = tc - ec;
	for (int i = 0;i < MAXINDEX;i++) {
		for (int j = 0;j < MAXINDEX;j++) {
			if (tmp[i][j])
				MAP[i - kr][j - kc][cnt] = 1;
		}
	}

	int tr2 = sc; int tc2 = MAXINDEX - 1 - sr;
	er = tr2 - kr; ec = tc2 - kc;
	int de = -1;
}
void solve()
{
	for (int t = 0;t < N;t++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		sr = y; sc = x;
		MAP[sr][sc][t] = 1;
		er = sr + dy[d];
		ec = sc + dx[d];
		MAP[er][ec][t] = 1;
		for (int i = 0;i < g;i++) {
			rotate(t);
		}
	}
	int arr[MAXINDEX][MAXINDEX] = { 0 };
	for (int i = 0;i < MAXINDEX;i++) {
		for (int j = 0;j < MAXINDEX;j++) {
			for (int k = 0;k < N;k++) {
				if (MAP[i][j][k]) {
					arr[i][j] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0;i < MAXINDEX - 1;i++) {
		for (int j = 0;j < MAXINDEX - 1;j++) {
			if (arr[i][j] && arr[i][j + 1] && arr[i + 1][j] && arr[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	solve();
}