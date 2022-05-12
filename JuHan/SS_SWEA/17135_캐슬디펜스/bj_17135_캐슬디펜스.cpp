#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

// �ϰ���
// N x M
// ���� (N+1)��
// �ü� 3�� ( ���� ��ġ ��ĭ)
// �ϸ��� �ü��� �� �ϳ� ����, ���ÿ� ����
// �ü��� �Ÿ��� D������ �� �� ���� ����� ��
// ������ ������ ���� ���� �Ʒ��� �̵�
// ���� �ִ� ĭ�� �����ϸ� ����
// ���� ��� ���ܵǸ� ���� ��

// �Է� N x M D(�Ÿ�)
// ��� : ���� �����ϴ� �ִ��
int N, M, D;
int map[16][15];
int score;
int maxScore;
int archer_row;
int used[15][15];
int direct[2][3] = {
	0, 0, -1,
	-1, 1, 0
};
int arr_archer[3];

int distance_map[15][15];
queue<pair<int,int>> q;
int kill[16][15];

void input() {
	cin >> N >> M >> D;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
}

int distance(int enemyY, int enemyX, int archerY, int archerX) {
	int dist = abs(enemyY - archerY) + abs(enemyX - archerX);
	return dist;
}

void bfs(int sy, int sx, int archer) {
	if (distance(sy, sx, archer_row, archer) > D)return;
	if ((used[sy][sx] != 0)&&(used[sy][sx]> distance(sy, sx, N, archer))) {
		used[sy][sx] = distance(sy, sx, N, archer);
	}
	else if (used[sy][sx] == 0) {
		used[sy][sx] = distance(sy, sx, N, archer);
	}

	for (int i = 0; i < 3; i++) {
		int dy = sy + direct[0][i];
		int dx = sx + direct[1][i];

		if (dy < 0 || dy >= N || dx < 0 || dx >= N || used[dy][dx] != 0)continue;
		bfs(dy, dx, archer);
	}
}

void move_archer() {
	for (int i = 0; i < M; i++) {
		if (map[archer_row][i] == 1) {
			map[archer_row][i] = 0;
		}
	}
	archer_row -= 1;
}

void play() {
	for (int i = 0; i < 3; i++) {
		bfs(N-1,arr_archer[i], arr_archer[i]);
	}

	//�� ���� ��, �� �̵�
	move_archer();
}

int archer_arrangement(int archer1, int archer2, int archer3) {
	// �ü� ��ġ
	archer_row = N;
	map[archer_row][archer1] = 2;
	map[archer_row][archer2] = 2;
	map[archer_row][archer3] = 2;

	arr_archer[0] = archer1;
	arr_archer[1] = archer2;
	arr_archer[2] = archer3;

	play();

	return score;
}

void archer() {
	for (int i = 0; i < M-2; i++) {
		for (int j = i + 1; j < M-1; j++) {
			for (int k = j + 1; k < M; k++) {
				archer_arrangement(i, j, k);
			}
		}
	}
}

void solve() {
	archer();
}

void solution() {
	input();
	solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	solution();

	return 0;
}