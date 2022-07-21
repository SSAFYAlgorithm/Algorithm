#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int H, W, Q;
int arr[130][130];

struct Node {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> H >> W;
	for (int r = 1; r <= H; r++) {
		for (int c = 1; c <= W; c++) {
			cin >> arr[r][c];
		}
	}

	cin >> Q;

	for (int a = 0; a < Q; a++) {
		int i, j, c;
		cin >> i >> j >> c;
		int target = arr[i][j];
		queue <Node> q;
		q.push({ i,j });
		int used[130][130] = { 0 };
		used[i][j] = 1;
		arr[i][j] = c;

		while (!q.empty()) {
			int now_y = q.front().y;
			int now_x = q.front().x;
			q.pop();
			for (int b = 0; b < 4; b++) {
				int next_y = now_y + dy[b];
				int next_x = now_x + dx[b];
				if (next_x <= 0 || next_y <= 0 || next_y > H || next_x > W) continue;
				if (arr[next_y][next_x] != target) continue;
				if (used[next_y][next_x]) continue;
				arr[next_y][next_x] = c;
				used[next_y][next_x] = 1;
				q.push({ next_y,next_x });
			}
		}
	}

	for (int y = 1; y <= H; y++) {
		for (int x = 1; x <= W; x++) {
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}