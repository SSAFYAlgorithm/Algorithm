#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int arr[101][101] = { 0 };
bool check[101][101] = { 0 };
int N, M;
int dfscnt = 1;
int bfscnt[102][102] = { 0 };
vector<int> minCount;

void dfs(int y, int x)		//dfs는 시간초과 뜬다고함;; 모든 경로를 탐색하므로 지수시간 걸림. 가중치가 동일한 경우 bfs를 이용하란다
{
	if (y == N && x == M) {
		minCount.push_back(dfscnt);
		return;
	}
	check[y][x] = 1;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };

	for (int i = 0;i < 4;i++) {
		int tempX = dx[i] + x;
		int tempY = dy[i] + y;
		if (!(tempX<1 || tempY<1 || tempX>M || tempY>N)) {
			if (arr[tempY][tempX]) {
				if (!check[tempY][tempX]) {
					dfscnt++;
					dfs(tempY, tempX);
					dfscnt--;

				}

			}
		}
	}
	check[y][x] = 0;
}
void bfs(int y, int x)
{
	queue<pair<int, int>> que;
	que.push(pair<int, int>(y, x));
	bfscnt[y][x] = 1;
	while (1)
	{
		//check[y][x] = 1;
		if (bfscnt[y - 1][x]) {					//경로가 호출될때마다 경로 배열에 1씩더함
			bfscnt[y][x] = bfscnt[y - 1][x] + 1;
		}
		else if (bfscnt[y][x - 1]) {
			bfscnt[y][x] = bfscnt[y][x - 1] + 1;
		}
		else if (bfscnt[y + 1][x]) {
			bfscnt[y][x] = bfscnt[y + 1][x] + 1;
		}
		else if (bfscnt[y][x + 1]) {
			bfscnt[y][x] = bfscnt[y][x + 1] + 1;
		}
		que.pop();


		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,-1,0,1 };
		for (int i = 0;i < 4;i++) {
			int tempX = dx[i] + x;
			int tempY = dy[i] + y;
			if (!(tempX<1 || tempY<1 || tempX>M || tempY>N)) {
				if (arr[tempY][tempX]) {
					if (!check[tempY][tempX]) {
						que.push(pair<int, int>(tempY, tempX));
						check[tempY][tempX] = 1;
					}


				}
			}
		}
		if (que.empty()) {
			break;
		}
		y = que.front().first;
		x = que.front().second;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		string strM;
		cin >> strM;
		for (int j = 0;j < M;j++) {
			arr[i][j + 1] = (int)(strM[j] - '0');
		}
	}
	//dfs(1, 1);
	bfs(1, 1);
	//sort(minCount.begin(), minCount.end());
	cout << bfscnt[N][M];
}