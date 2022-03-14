#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <fstream>

using namespace std;

int n, w, h, temp, ans = 0;
int arr[20][20];
int copyArr[20][20];
int ballCount[20];
int copyBallCount[20];

vector<vector<int>> ballCase;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void make(int depth, vector<int> next) {
	if (depth == n) {
		ballCase.push_back(next);
		return;
	}
	for (int i = 0; i < w; i++) {
		if (copyBallCount[i] != 0) {
			next.push_back(i);
			copyBallCount[i]--;
			make(depth + 1, next);
			copyBallCount[i]++;
			next.erase(next.end()-1);
		}
	}
}

void copy() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			copyArr[i][j] = arr[i][j];
		}
	}
}

void deleteBrick(int x, int y) {
	int num = copyArr[x][y];
	queue<pair<pair<int, int>,int>> q;
	q.push({ {x,y},num });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (copyArr[x][y] == 0)
			continue;
		if (cnt == 1) {
			copyArr[x][y] = 0;
			continue;
		}
		copyArr[x][y] = 0;

		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = x + (dx[j] * i);
				int ny = y + (dy[j] * i);
				if (nx >= 0 && nx < h && ny >= 0 && ny < w && copyArr[nx][ny] != 0) {
					q.push({ {nx,ny}, copyArr[nx][ny] });
				}
				if (i == 0)
					continue;
			}
		}
		
	}

}

void dropBrick() {

	for (int i = h - 1; i > 0; i--) {
		for (int j = 0; j < w; j++) {
			bool flag = false;
			if (copyArr[i][j] == 0) {
				int tempIndex = i - 1;
				while (tempIndex >= 0) {
					if (copyArr[tempIndex][j] != 0) {
						flag = true;
						break;
					}
					tempIndex--;
				}

				if (flag == true) {
					copyArr[i][j] = copyArr[tempIndex][j];
					copyArr[tempIndex][j] = 0;
				}
			}
		}
	}
}

void shootBall(int n) {
	for (int i = 0; i < h; i++) {
		if (copyArr[i][n] != 0) {
			deleteBrick(i, n);
			dropBrick();
			break;
		}
	}
}

int checkBrick() {
	int result = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (copyArr[i][j] != 0)
				result++;
		}
	}
	return result;
}

int main() {
	int testcase;
	//ifstream is("input.txt");
	//is >> testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		/////////////////init//////////////////
		memset(arr, 0, sizeof(arr));
		memset(ballCount, 0, sizeof(ballCount));
		ballCase.clear();
		ans = 987654321;

		////////////////input///////////////////
		cin >> n >> w >> h;
		//is >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//is >> arr[i][j];
				cin >> arr[i][j];
				if (arr[i][j] != 0)
					ballCount[j]++;
			}
		}
		////////////////////////////////////////
		
		////////////조합 만들기///////////////
		for (int i = 0; i < w; i++) {
			copyBallCount[i] = ballCount[i];
		}
		vector<int> temptemp;
		make(0,temptemp);

		///////////////////던지기/////////////
		for (int i = 0; i < ballCase.size(); i++) {
			memset(copyArr, 0, sizeof(copyArr));
			copy();
			
			for (int j = 0; j < n; j++) {
				shootBall(ballCase[i][j]);
			}
			ans = min(ans, checkBrick());
			if (ans == 0)
				break;
			
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}