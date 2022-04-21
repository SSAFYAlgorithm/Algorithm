#include <iostream>

using namespace std;

int R, C, T;
int dust[50][50];
int dir[2][4] = {
	0,0,-1,1,
	-1,1,0,0
};
int airCleaner_topPoint[2]; // 공기청정기 윗부분 좌표
int airCleaner_bottomPoint[2]; // 공기청정기 아랫부분 좌표
int total_dust;
int add[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> R >> C >> T;
	bool part_check = false; // 공기청정기 위-1, 아래-1 구분
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> dust[y][x];
			if (dust[y][x] == -1) {
				if (!part_check) {
					airCleaner_topPoint[0] = y;
					airCleaner_topPoint[1] = x;
					part_check = true;
				}
				else if (part_check) {
					airCleaner_bottomPoint[0] = y;
					airCleaner_bottomPoint[1] = x;
				}
			}
			else if (dust[y][x] != 0) {
				total_dust += dust[y][x];
			}
		}
	}

	while (T--) {
		// T가 줄어들때마다 먼지 확산
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				int block_cnt = 0; // 먼지가 퍼진 칸 수
				int move_dust_amount = dust[y][x] / 5; // 먼지 이동
				if (dust[y][x] == 0 || dust[y][x] == -1) continue;
				for (int d = 0; d < 4; d++) {
					int dy = y + dir[0][d];
					int dx = x + dir[1][d];
					if (dy < 0 || dy >= R || dx < 0 || dx >= C)continue; // 범위밖
					if (dust[dy][dx] == -1) continue; // 이동하는 먼지가 공기청정기 만날때
					add[dy][dx] += move_dust_amount;
					block_cnt++;
				}
				add[y][x] -= (block_cnt * move_dust_amount);
			}
		}

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				dust[y][x] += add[y][x];
				add[y][x] = 0; // 덧셈배열 더해주고 초기화
			}
		}

		total_dust -= dust[airCleaner_topPoint[0] - 1][0];
		total_dust -= dust[airCleaner_bottomPoint[0] + 1][0];

		// 윗부분 (반시계회전)
		for (int i = airCleaner_topPoint[0] - 1; i > 0; i--) {
			dust[i][0] = dust[i - 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			dust[0][i] = dust[0][i + 1];
		}
		for (int i = 1; i <= airCleaner_topPoint[0]; i++) {
			dust[i - 1][C - 1] = dust[i][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			dust[airCleaner_topPoint[0]][i] = dust[airCleaner_topPoint[0]][i - 1];
		}
		dust[airCleaner_topPoint[0]][1] = 0;


		// 아랫부분 (시계회전)
		for (int i = airCleaner_bottomPoint[0] + 1; i < R - 1; i++) {
			dust[i][0] = dust[i + 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			dust[R - 1][i] = dust[R - 1][i + 1];
		}
		for (int i = R - 1; i >= airCleaner_bottomPoint[0]; i--) {
			dust[i][C - 1] = dust[i - 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			dust[airCleaner_bottomPoint[0]][i] = dust[airCleaner_bottomPoint[0]][i - 1];
		}
		dust[airCleaner_bottomPoint[0]][1] = 0;
	}
	cout << total_dust << '\n';

	return 0;
}