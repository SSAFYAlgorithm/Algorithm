#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int NN, Q;
int N;
int arr[70][70];
int used[70][70];
int Narr[70][70] = { 0 };
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int CountNum[4000];
struct Node {
	int y, x;
};

// 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다.
// L이 1이면 4개
void Turn(int L) {
	memset(Narr, 0, sizeof(Narr));
	int Di = (int)pow(2, L);

	// 0<=y<Di / 0 이상 Di 미만까지 1구역 , Di 부터 끝까지 2구역
	// Di<=y<N / 0 ~ Di미만 3구역, Di부터 끝까지 4구역

	for (int yy = 0; yy < N; yy += Di) {
		for (int xx = 0; xx < N; xx += Di) {
			int sy = yy;
			int ey = yy + Di - 1;
			int sx = xx;
			int ex = xx + Di - 1;
			while (1) {
				int Cha = ey - sy + 1;
				// 맨 위 -> 오른쪽
				for (int y = 0; y < Cha - 1; y++) {
					Narr[sy + y][ex] = arr[sy][sx + y];
				}

				// 맨 오른쪽 -> 아래
				for (int y = 0; y < Cha - 1; y++) {
					Narr[ey][ex - y] = arr[sy + y][ex];
				}

				// 맨 아래 -> 왼쪽
				for (int y = 0; y < Cha - 1; y++) {
					Narr[ey - y][sx] = arr[ey][ex - y];
				}

				// 맨 왼쪽 -> 위쪽
				for (int y = 0; y < Cha - 1; y++) {
					Narr[sy][sx + y] = arr[ey - y][sx];
				}
				sx++;
				sy++;
				ey--;
				ex--;
				if (sx >= ex || sy >= ey) break;
			}
		}
	}


	memcpy(arr, Narr, sizeof(arr));
}

// 얼음이 있는 칸 3개이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다.
// 상하좌우에 얼음이 없는 칸이 2개 이상일 경우 얼음 수치 -1 됨.
void Erase() {
	memcpy(Narr, arr, sizeof(arr));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (arr[y][x] == 0) continue;
			int Count = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (arr[ny][nx] > 0) Count++;
			}
			if (Count < 3) Narr[y][x]--;
		}
	}
	memcpy(arr, Narr, sizeof(arr));
}

int num = 1;
void FindNum() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (used[y][x] != 0) continue;
			if (arr[y][x] == 0) continue;
			queue <Node> q;
			q.push({ y,x });
			used[y][x] = num;
			while (!q.empty()) {
				int nowy = q.front().y;
				int nowx = q.front().x;
				q.pop();
				CountNum[num]++;
				for (int i = 0; i < 4; i++) {
					int ny = nowy + dy[i];
					int nx = nowx + dx[i];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
					if (used[ny][nx] != 0)continue;
					if (arr[ny][nx] == 0) continue;
					used[ny][nx] = num;
					q.push({ ny,nx });
				}
			}
			num++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> NN >> Q;
	N = (int)pow(2, NN);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		int L;
		cin >> L;
		if (L != 0) {
			Turn(L);
		}
		Erase();
	}

	int res1 = 0;
	int res2 = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			res1 += arr[y][x];
		}
	}

	// 덩어리찾기
	FindNum();

	for (int i = 1; i < num; i++) {
		if (CountNum[i] <= 1) continue;
		if (CountNum[i] > res2) res2 = CountNum[i];
	}

	if (res2 == 0) {
		cout << 0 << endl << 0;
	}
	else {
		cout << res1 << endl << res2;
	}

	return 0;
}