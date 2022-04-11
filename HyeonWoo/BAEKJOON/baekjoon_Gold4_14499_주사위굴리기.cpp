#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int SY, SX;
int K;
int MAP[25][25];
int dice[6]; // 위 앞 밑 뒤 오 왼
int DoIt[1010];

void South() {
	int temp[6] = {0};
	temp[0] = dice[1];
	temp[1] = dice[2];
	temp[2] = dice[3];
	temp[3] = dice[0];
	temp[4] = dice[4];
	temp[5] = dice[5];
	memcpy(dice, temp, sizeof(dice));
}

void North() {
	int temp[6] = { 0 };
	temp[0] = dice[3];
	temp[1] = dice[0];
	temp[2] = dice[1];
	temp[3] = dice[2];
	temp[4] = dice[4];
	temp[5] = dice[5];
	memcpy(dice, temp, sizeof(dice));
}

void East() {
	int temp[6] = { 0 };
	temp[0] = dice[4];
	temp[1] = dice[1];
	temp[2] = dice[5];
	temp[3] = dice[3];
	temp[4] = dice[2];
	temp[5] = dice[0];
	memcpy(dice, temp, sizeof(dice));
}

void West() {
	int temp[6] = { 0 };
	temp[0] = dice[5];
	temp[1] = dice[1];
	temp[2] = dice[4];
	temp[3] = dice[3];
	temp[4] = dice[0];
	temp[5] = dice[2];
	memcpy(dice, temp, sizeof(dice));
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> M >> SY >> SX >> K;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> MAP[y][x];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> DoIt[i];
	}
	
	// 0번이 위 (출력), 2번이 밑(갱신)이다
	int y = SY;
	int x = SX;
	for (int i = 0; i < K; i++) {
		// East
		if (DoIt[i] == 1) {
			int ny = y;
			int nx = x + 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			y = ny;
			x = nx;
			East();
			//먼저 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
			if (MAP[y][x] == 0) {
				MAP[y][x] = dice[2];
			}
			// 0이 아니면 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
			else {
				dice[2] = MAP[y][x];
				MAP[y][x] = 0;
			}
			// 마지막으로 윗면 출력
			cout << dice[0] << endl;
		}

		// West
		else if (DoIt[i] == 2) {
			int ny = y;
			int nx = x - 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			y = ny;
			x = nx;
			West();
			//먼저 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
			if (MAP[y][x] == 0) {
				MAP[y][x] = dice[2];
			}
			// 0이 아니면 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
			else {
				dice[2] = MAP[y][x];
				MAP[y][x] = 0;
			}
			// 마지막으로 윗면 출력
			cout << dice[0] << endl;
		}

		// North
		else if (DoIt[i] == 3) {
			int ny = y - 1;
			int nx = x;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			y = ny;
			x = nx;
			North();
			//먼저 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
			if (MAP[y][x] == 0) {
				MAP[y][x] = dice[2];
			}
			// 0이 아니면 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
			else {
				dice[2] = MAP[y][x];
				MAP[y][x] = 0;
			}
			// 마지막으로 윗면 출력
			cout << dice[0] << endl;
		}

		// South
		else if (DoIt[i] == 4) {
			int ny = y + 1;
			int nx = x;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			y = ny;
			x = nx;
			South();
			//먼저 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
			if (MAP[y][x] == 0) {
				MAP[y][x] = dice[2];
			}
			// 0이 아니면 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
			else {
				dice[2] = MAP[y][x];
				MAP[y][x] = 0;
			}
			// 마지막으로 윗면 출력
			cout << dice[0] << endl;
		}
		
	}


	return 0;
}