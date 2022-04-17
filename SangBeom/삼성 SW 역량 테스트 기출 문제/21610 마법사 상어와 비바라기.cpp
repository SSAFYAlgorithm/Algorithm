#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int N, M;
int A[51][51];
vector<pair<int, int>>vect;
int cloud[51][51];

void cloudMove(int n) {
	int temp[51][51] = { 0 };
	int dr[] = { 0,0,-1,-1,-1,0,1,1,1 };
	int dc[] = { 0,-1,-1,0,1,1,1,0,-1 };
	pair<int, int>now = vect[n];
	int s = now.second % N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (cloud[i][j]) {
				int tr = dr[now.first] * s + i;
				int tc = dc[now.first] * s + j;
				if (tr < 0) tr = N + tr;
				else if (tr >= N)tr = tr - N;

				if (tc < 0)tc = N + tc;
				else if (tc >= N) tc = tc - N;
				temp[tr][tc] = 1;
			}
		}
	}
	memcpy(cloud, temp, sizeof(cloud));
}
void rain()
{
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (cloud[i][j]) {
				A[i][j]++;
			}
		}
	}
}
void magic()
{
	int dr[] = { -1,1,1,-1 };
	int dc[] = { -1,-1,1,1 };
	int tmp[51][51] = { 0 };
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (cloud[i][j]) {
				int cnt = 0;
				for (int k = 0;k < 4;k++) {
					int tr = dr[k] + i;
					int tc = dc[k] + j;
					if (tr < 0 || tc < 0 || tr >= N || tc >= N)continue;
					if (A[tr][tc])cnt++;
				}
				tmp[i][j] = cnt;
			}
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (tmp[i][j]) {
				A[i][j] += tmp[i][j];
			}
		}
	}
}
void makeCloud()
{
	int tmp[51][51] = { 0 };
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (cloud[i][j])continue;
			if (A[i][j] >= 2) {
				tmp[i][j] = 1;
				A[i][j] -= 2;
			}
		}
	}
	memcpy(cloud, tmp, sizeof(cloud));
}
int solve()
{
	for (int i = 0;i < M;i++) {
		cloudMove(i);
		rain();
		magic();
		//memset(cloud, 0, sizeof(cloud));
		makeCloud();
	}
	int sum = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			sum += A[i][j];
		}
	}
	return sum;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0;i < M;i++) {
		int d, s;
		cin >> d >> s;
		vect.push_back(pair<int, int>(d, s));
	}
	cloud[N - 1][0] = 1;
	cloud[N - 2][0] = 1;
	cloud[N - 1][1] = 1;
	cloud[N - 2][1] = 1;
	cout << solve();

}