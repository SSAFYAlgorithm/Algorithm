#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int N, M, K;
int arr[30][30];

int dy[4] = { 0, 1, 0, -1 }; // 동 남 서 북 (시계방향)
int dx[4] = { 1, 0, -1, 0 };
int dir = 0;
int Score;
int dice[] = {1,5,6,2,3,4}; // 위, 앞, 밑, 뒤, 오, 왼

int nowY = 1;
int nowX = 1;

struct Node {
	int y, x;
};

void Right() {
	// idx  : 위, 앞, 밑, 뒤, 오, 왼
	// after: 왼, 앞, 오, 뒤, 위, 밑
	int ndice[6] = {0};
	ndice[0] = dice[5];
	ndice[1] = dice[1];
	ndice[2] = dice[4];
	ndice[3] = dice[3];
	ndice[4] = dice[0];
	ndice[5] = dice[2];
	memcpy(dice, ndice, sizeof(dice));
}

void Left() {
	// idx  : 위, 앞, 밑, 뒤, 오, 왼
	// after: 오, 앞, 왼, 뒤, 밑, 위
	int ndice[6] = { 0 };
	ndice[0] = dice[4];
	ndice[1] = dice[1];
	ndice[2] = dice[5];
	ndice[3] = dice[3];
	ndice[4] = dice[2];
	ndice[5] = dice[0];
	memcpy(dice, ndice, sizeof(dice));
}

void Front() {
	// idx  : 위, 앞, 밑, 뒤, 오, 왼
	// after: 뒤, 위, 앞, 밑, 오, 왼
	int ndice[6] = { 0 };
	ndice[0] = dice[3];
	ndice[1] = dice[0];
	ndice[2] = dice[1];
	ndice[3] = dice[2];
	ndice[4] = dice[4];
	ndice[5] = dice[5];
	memcpy(dice, ndice, sizeof(dice));
}

void Back() {
	// idx  : 위, 앞, 밑, 뒤, 오, 왼
	// after: 앞, 밑, 뒤, 위, 오, 왼
	int ndice[6] = { 0 };
	ndice[0] = dice[1];
	ndice[1] = dice[2];
	ndice[2] = dice[3];
	ndice[3] = dice[0];
	ndice[4] = dice[4];
	ndice[5] = dice[5];
	memcpy(dice, ndice, sizeof(dice));
}

// (x, y)에 있는 정수를 B라고 했을때,
// (x, y)에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수 C를 모두 구한다. 
// 이동할 수 있는 칸에는 모두 정수 B가 있어야 한다. 
// 여기서 점수는 B와 C를 곱한 값이다.
void GetScore() {
	queue <Node> q;
	int standard = arr[nowY][nowX];
	q.push({ nowY,nowX });
	int Count = 0;
	int used[30][30] = { 0 };
	used[nowY][nowX] = 1;
	// standard와 같은값의 개수 찾기
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		Count++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
			if (standard != arr[ny][nx]) continue;
			if (used[ny][nx] != 0) continue;
			used[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	Score += (standard) * (Count);
}

void Move() {
	// 동 남 서 북 (시계방향)
	// 주사위 이동
	int ny = nowY + dy[dir];
	int nx = nowX + dx[dir];
	if (nx <= 0 || ny<=0 || ny > N || nx > M) {
		if (dir < 2) {
			dir += 2;
		}
		else {
			dir -= 2;
		}
	}
	nowY += dy[dir];
	nowX += dx[dir];

	if (dir == 0) {
		Right(); // 동
	}
	else if (dir == 1) {
		Front(); // 남
	}
	else if (dir == 2) {
		Left(); // 서
	}
	else if (dir == 3) {
		Back(); // 북
	}

	// score 얻기
	GetScore();
	
	// 방향 정하기
	int A = dice[2];
	int B = arr[nowY][nowX];
	if (A > B) {
		dir = (dir + 1) % 4;
	}
	else if (A < B) {
		dir = (dir - 1);
		if (dir == -1) {
			dir = 3;
		}
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
	//위, 앞, 밑, 뒤, 오, 왼
	for (int i = 0; i < K; i++) {
		Move();
	}

	cout << Score;
	return 0;
}