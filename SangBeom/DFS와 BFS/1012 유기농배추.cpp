#include<iostream>
#include<vector>

using namespace std;
int arr[51][51] = { 0 };
bool check[51][51] = { 0 };
int flag;
int N, M, K;
int cnt = 0;
void dfs(int py, int px)		//테스트케이스 통과, 반례??
{
	flag = 1;
	check[py][px] = 1;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	for (int i = 0;i < 4;i++) {
		int tempX = px + dx[i];
		int tempY = py + dy[i];
		if (!(tempX<0 || tempY<0 || tempX>N || tempY>M)) {
			if (arr[tempY][tempX]) {
				if (!check[tempY][tempX]) {
					dfs(tempY, tempX);
				}
			}
		}
	}
}

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0;i < testCase;i++) {
		cnt = 0;

		cin >> N >> M >> K;
		for (int position = 0; position < K;position++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int j = 0;j < M;j++) {
			for (int k = 0;k < N;k++) {
				if (arr[j][k]) {
					if (!check[j][k]) {
						dfs(j, k);
					}
				}
				if (flag == 1) {
					cnt++;
				}
				flag = 0;
			}
		}
		cout << cnt << '\n';
	}
}