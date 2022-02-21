#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int arr[101][101][101];
int check[101][101][101] = { 0 };
int N, M, H;
queue<tuple<int, int, int>> que;


int main()
{
	cin >> M >> N >> H;
	for (int k = 0;k < H;k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					que.push(tuple<int, int, int>(i, j, k));
					check[i][j][k] = 1;
				}
				if (arr[i][j][k] == -1) {
					check[i][j][k] = -1;
				}
			}
		}
	}

	int dy[6] = { 0,-1,0,1,0,0 };
	int dx[6] = { -1,0,1,0,0,0 };
	int dz[6] = { 0,0,0,0,-1,1 };
	while (1)
	{
		if (que.empty()) break;
		int y = get<0>(que.front());
		int x = get<1>(que.front());
		int z = get<2>(que.front());
		que.pop();

		for (int i = 0;i < 6;i++) {
			int tempY = dy[i] + y;
			int tempX = dx[i] + x;
			int tempZ = dz[i] + z;
			if (!(tempX < 0 || tempY < 0 || tempX >= M || tempY >= N || tempZ < 0 || tempZ >= H)) {
				if (arr[tempY][tempX][tempZ] == 0) {
					arr[tempY][tempX][tempZ] = 1;
					check[tempY][tempX][tempZ] = check[y][x][z] + 1;
					que.push(tuple<int, int, int>(tempY, tempX, tempZ));
				}

				//if (arr[tempY][tempX] == -1)
			}
		}

	}
	bool flag = true;
	int max = -1;
	for (int k = 0;k < H;k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (check[i][j][k] == 0) {
					flag = false;
					break;
				}
				if (max < check[i][j][k]) {
					max = check[i][j][k];
				}
			}
		}
	}
	if (flag) cout << max - 1;
	else cout << -1;



}