#include <iostream>


using namespace std;

// dir : 0 북 1 동 2 남 3 서
int N, M, sy, sx, dir;
int arr[60][60];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt = 0; // 몇번 회전할지
int res = 0; // 몇번 청소할지

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> sy >> sx >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int y = sy;
	int x = sx;
	
	while (1) {
		// 현재위치가 빈공간이면 
		if (arr[y][x] == 0) {
			arr[y][x] = 2;
			res++;
		}
		else {
			cnt++;
			// 4번 회전이 끝났다면
			if (cnt == 5) {
				cnt = 0;
				// 후진
				int ny = y + dy[(dir + 2) % 4];
				int nx = x + dx[(dir + 2) % 4];
				if (arr[ny][nx] == 1) break;
				y = ny;
				x = nx;
				continue;
			}

			dir = (dir + 4 -1) % 4;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx] != 0) continue;
			y = ny;
			x = nx;
			cnt = 0;
		}
	}

	cout << res;
	return 0;
}