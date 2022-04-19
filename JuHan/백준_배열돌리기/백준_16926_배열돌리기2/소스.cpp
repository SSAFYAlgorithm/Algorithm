#include <iostream>
#include <algorithm>

using namespace std;

int arr[301][301];

int dir[2][4] = {
	0,0,-1,1,
	-1,1,0,0
};

int main() {
	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = min(N, M) / 2;
	int n = N;
	int m = M;

	for (int i = 0; i < cnt; i++) {
		int r = R % (2 * n + 2 * m - 4);
		for (int j = 0; j < r; j++) {
			int start = arr[i][i];
			int y = start;
			int x = start;

			int k = 0;
			while (k < 4) {
				int dy = y + dir[0][k];
				int dx = x + dir[1][k];

				if (dy == start && dx == start)break;
				if (start <= dy && dy < N - start && start <= dx && dx < M - start) {
					arr[y][x] = arr[dy][dx];
					y = dy;
					x = dx;
				}
				else k++;
			}
			arr[i + 1][i] = start;
		}
		n -= 2;
		m -= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}