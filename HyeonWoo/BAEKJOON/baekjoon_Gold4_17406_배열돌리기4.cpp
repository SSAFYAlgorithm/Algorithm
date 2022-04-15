#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, K;
int arr[55][55];
int initarr[55][55];
int res = 21e8;
struct rcs {
	int r, c, s;
};

vector <rcs> vect;
int used[10];
vector <rcs> path;

int findMin() {
	int MIN = 21e8;
	for (int y = 1; y <= N; y++) {
		int SUM = 0;
		for (int x = 1; x <= M; x++) {
			SUM += arr[y][x];
		}
		if (SUM < MIN) {
			MIN = SUM;
		}
	}
	return MIN;
}

void Turn(int r, int c, int s) {
	int sy = r - s;
	int sx = c - s;
	int ey = r + s;
	int ex = c + s;
	int temp[55][55];
	memcpy(temp, arr, sizeof(arr));
	while (1) {
		// 위
		for (int x = sx + 1; x <= ex; x++) {
			temp[sy][x] = arr[sy][x - 1];
		}
		// 오
		for (int y = sy + 1; y <= ey; y++) {
			temp[y][ex] = arr[y - 1][ex];
		}
		// 아
		for (int x = ex - 1; x >= sx; x--) {
			temp[ey][x] = arr[ey][x + 1];
		}
		// 왼
		for (int y = ey - 1; y >= sy; y--) {
			temp[y][sx] = arr[y + 1][sx];
		}
		sx++; sy++; ex--; ey--;
		if (sx >= ex || sy >= ey) break;
	}
	memcpy(arr, temp, sizeof(arr));

}


void dfs(int level) {
	if (level == K) {
		// 해당순서로 배열돌린 후 최소값 구한다
		memcpy(arr, initarr, sizeof(arr));
		for (int i = 0; i < K; i++) {
			int r = path[i].r;
			int c = path[i].c;
			int s = path[i].s;
			Turn(r, c, s);
		}
		// 이후 최소값 계산
		int Temp = findMin();
		if (Temp < res) {
			res = Temp;
		}
	}
	for (int i = 0; i < K; i++) {
		if (used[i] != 0) continue;
		used[i] = 1;
		path.push_back(vect[i]);
		dfs(level + 1);
		path.pop_back();
		used[i] = 0;
	}
	
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		vect.push_back({ r,c,s });
	}
	memcpy(initarr, arr, sizeof(arr));

	// DFS로 어떤순서로 돌릴껀지 결정
	dfs(0);
	
	cout << res;
	return 0;
}