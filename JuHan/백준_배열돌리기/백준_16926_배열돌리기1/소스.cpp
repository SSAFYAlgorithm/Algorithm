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
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < cnt; j++) {
			int start = arr[i][i];

			int y = i;
			int x = i;

			int k = 0;
			while(k<4){
				int dy = y + dir[0][k];
				int dx = x + dir[1][k];

				if (dy == i && dx == i)break;
				if (i <= dy && dy < N - i && i <= dx && dx < M - i) {
					arr[y][x] = arr[dy][dx];
					y = dy;
					x = dx;
				}
				else k++;
			}
			arr[i + 1][i] = start;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
	
}