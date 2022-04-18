#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int arr[10][10];
int initarr[10][10];
int res = 21e8;
struct Node {
	int y;
	int x;
	int type;
};

vector <Node> CCTV;

void Right(int yy, int xx) {
	int y = yy;
	int x = xx;
	while (1) {
		int nexty = y;
		int nextx = x+1;
		if (nexty < 0 || nextx < 0 || nexty >= N || nextx >= M) break;
		if (arr[nexty][nextx] == 6) break;
		arr[nexty][nextx] = 9;
		y = nexty;
		x = nextx;
	}
	
}
void Left(int yy, int xx) {
	int y = yy;
	int x = xx;
	while (1) {
		int nexty = y;
		int nextx = x-1;
		if (nexty < 0 || nextx < 0 || nexty >= N || nextx >= M) break;
		if (arr[nexty][nextx] == 6) break;
		arr[nexty][nextx] = 9;
		y = nexty;
		x = nextx;
	}
}
void Up(int yy, int xx) {
	int y = yy;
	int x = xx;
	while (1) {
		int nexty = y-1;
		int nextx = x;
		if (nexty < 0 || nextx < 0 || nexty >= N || nextx >= M) break;
		if (arr[nexty][nextx] == 6) break;
		arr[nexty][nextx] = 9;
		y = nexty;
		x = nextx;
	}
}
void Down(int yy, int xx) {
	int y = yy;
	int x = xx;
	while (1) {
		int nexty = y + 1;
		int nextx = x;
		if (nexty < 0 || nextx < 0 || nexty >= N || nextx >= M) break;
		if (arr[nexty][nextx] == 6) break;
		arr[nexty][nextx] = 9;
		y = nexty;
		x = nextx;
	}
}

int CountZero() {
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x] == 0) cnt++;
		}
	}
	return cnt;
}




// 완전탐색으로 방향을 정해줘야한다
// 1번 : 오 왼 아 위					(4)
// 2번 : 오왼 아위						(2)
// 3번 : 오위 위왼 왼아 아오			(4)
// 4번 : 오위왼 위왼아 왼아오 아오위	(4)
// 5번 : 오위왼아						(1)

struct Number {
	int sy;
	int sx;
	int idx;
	int type;
};

vector <Number> path;
void dfs(int idx) {
	if (idx == CCTV.size()) {
		// 도착하면 path경우대로 arr 채운다.
		memcpy(arr, initarr, sizeof(arr));
		for (int i = 0; i < path.size(); i++) {
			int sy = path[i].sy;
			int sx = path[i].sx;
			int useIdx = path[i].idx;
			int type = path[i].type;
			// 1번 : 오 왼 아 위					(4)
			if (type == 1) {
				if (useIdx == 0) Right(sy,sx);
				else if (useIdx == 1) Left(sy,sx);
				else if (useIdx == 2) Down(sy,sx);
				else if (useIdx == 3) Up(sy,sx);
			}
			// 2번 : 오왼 아위						(2)
			else if (type == 2) {
				if (useIdx == 0) {
					Right(sy, sx);
					Left(sy, sx);
				}
				else if (useIdx == 1) {
					Up(sy, sx);
					Down(sy, sx);
				}
			}
			// 3번 : 오위 위왼 왼아 아오			(4)
			else if (type == 3) {
				if (useIdx == 0) {
					Right(sy, sx);
					Up(sy, sx);
				}
				else if (useIdx == 1) {
					Up(sy, sx);
					Left(sy, sx);
				}
				else if (useIdx == 2) {
					Left(sy, sx);
					Down(sy, sx);
				}
				else if (useIdx == 3) {
					Down(sy, sx);
					Right(sy, sx);
				}
			}
			// 4번 : 오위왼 위왼아 왼아오 아오위	(4)
			else if (type == 4) {
				if (useIdx == 0) {
					Right(sy, sx);
					Up(sy, sx);
					Left(sy, sx);
				}
				else if (useIdx == 1) {
					Up(sy, sx);
					Left(sy, sx);
					Down(sy, sx);
				}
				else if (useIdx == 2) {
					Left(sy, sx);
					Down(sy, sx);
					Right(sy, sx);
				}
				else if (useIdx == 3) {
					Down(sy, sx);
					Right(sy, sx);
					Up(sy, sx);
				}

			}
			// 5번 : 오위왼아						(1)
			else if (type == 5) {
				Right(sy, sx);
				Up(sy, sx);
				Left(sy, sx);
				Down(sy, sx);
			}
		}

		int temp = CountZero();
		if (temp < res) {
			res = temp;
		}
		return;
	}

	if (CCTV[idx].type == 2) {
		// 2번타입은 두가지경우만 존재
		for (int i = 0; i < 2; i++) {
			path.push_back({ CCTV[idx].y,CCTV[idx].x,i,2 });
			dfs(idx + 1);
			path.pop_back();
		}
	}
	else if (CCTV[idx].type == 5) {
		// 5번타입은 1가지경우
		path.push_back({ CCTV[idx].y,CCTV[idx].x,0,5 });
		dfs(idx + 1);
		path.pop_back();
	}
	else {
		// 그외는 모두 4가지경우
		for (int i = 0; i < 4; i++) {
			path.push_back({ CCTV[idx].y,CCTV[idx].x,i,CCTV[idx].type });
			dfs(idx + 1);
			path.pop_back();
		}
	}
}


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
			if (arr[y][x] >= 1 && arr[y][x] <= 5) CCTV.push_back({ y,x,arr[y][x]});
		}
	}

	// 초기화
	memcpy(initarr, arr, sizeof(arr));

	dfs(0);
	
	cout << res;
	return 0;
}