#include<iostream>
#include<queue>

using namespace std;

int arr[1001][1001];
int check[1001][1001] = { 0 };
int N, M;
queue<pair<int, int>> que;



int main()
{
	cin >> M >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				que.push(pair<int, int>(i, j));
				check[i][j] = 1;
			}
			if (arr[i][j] == -1) {
				check[i][j] = -1;
			}
		}
	}

	int dy[4] = { 0,-1,0,1 };
	int dx[4] = { -1,0,1,0 };
	while (1)
	{
		if (que.empty()) break;
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0;i < 4;i++) {
			int tempY = dy[i] + y;
			int tempX = dx[i] + x;
			if (!(tempX < 0 || tempY < 0 || tempX >= M || tempY >= N)) {
				if (arr[tempY][tempX] == 0) {
					arr[tempY][tempX] = 1;
					check[tempY][tempX] = check[y][x] + 1;
					que.push(pair<int, int>(tempY, tempX));
				}

				//if (arr[tempY][tempX] == -1)
			}
		}

	}
	bool flag = true;
	int max = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (check[i][j] == 0) {
				flag = false;
				break;
			}
			if (max < check[i][j]) {
				max = check[i][j];
			}
		}
	}
	if (flag) cout << max - 1;
	else cout << -1;



}