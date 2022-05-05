#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int red[4][4];
int blue[4][6]; // x가 0~1은 라이트블루
int green[6][4]; // y가 0~1은 라이트 그린
int score = 0;
int CheckY[4];
int CheckX[4]; // 현재 red에 놓은 블럭이 걸쳐지는 위치 및 몇개인지 체크

void BombBlue() {
	for (int x = 2; x < 6; x++) {
		int flag = 0;
		for (int y = 0; y < 4; y++) {
			if (blue[y][x] == 0) {
				flag = 1;
				break;
			}
		}
		// 모두가 1이라면 해당부분 0으로 초기화후 땡겨옴
		if (!flag) {
			for (int y = 0; y < 4; y++) {
				blue[y][x] = 0;
			}
			for (int xx = x; xx >= 1; xx--) {
				for (int y = 0; y < 4; y++) {
					blue[y][xx] = blue[y][xx - 1];
				}
			}
			for (int y = 0; y < 4; y++) {
				blue[y][0] = 0;
			}
			score++;
		}
	}
}

void BombGreen() {
	for (int y = 2; y < 6; y++) {
		int flag = 0;
		for (int x = 0; x < 4; x++) {
			if (green[y][x] == 0) {
				flag = 1;
				break;
			}
		}
		// 모두가 1이라면 해당부분 0으로 초기화후 땡겨옴
		if (!flag) {
			for (int x = 0; x < 4; x++) {
				green[y][x] = 0;
			}
			for (int yy = y; yy >= 1; yy--) {
				for (int x = 0; x < 4; x++) {
					green[yy][x] = green[yy - 1][x];
				}
			}
			for (int x = 0; x < 4; x++) {
				green[0][x] = 0;
			}
			score++;
		}

	}
}

void PushBlue(int how) {
	int Temp[4][6] = { 0 };
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 6-how; x++) {
			Temp[y][x + how] = blue[y][x];
		}
	}
	memcpy(blue, Temp, sizeof(blue));
}

void RtoB(int t) {
	if (t == 1) { //1개짜리
		int idx = 0;
		for (int y = 0; y < 4; y++) {
			if (CheckY[y] == 1) idx = y;
		}

		int flag = 0;
		for (int x = 1; x < 6; x++) {
			if (blue[idx][x] != 0) {
				blue[idx][x - 1] = 1;
				flag = 1;
				break;
			}
		}

		if (!flag) {
			blue[idx][5] = 1;
		}
	}
	else if (t == 2) { // 가로2줄짜리
		int idx = 0;
		for (int y = 0; y < 4; y++) {
			if (CheckY[y] == 2) idx = y;
		}

		int flag = 0;
		for (int x = 2; x < 6; x++) {
			if (blue[idx][x] != 0) {
				blue[idx][x - 2] = 1;
				blue[idx][x - 1] = 1;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			blue[idx][5] = 1;
			blue[idx][4] = 1;
		}
	}
	else if (t == 3) { // 세로2줄짜리
		
		int flag = 0; // 채우는지 안채우는지 판별
		for (int x = 1; x < 6; x++) {
			for (int y = 0; y < 4; y++) {
				if (CheckY[y] == 0) continue;
				if (blue[y][x] == 0) continue;
				for (int yy = 0; yy < 4; yy++) {
					if (CheckY[yy] == 0) continue;
					blue[yy][x - 1] = 1;
					flag = 1;
				}
				break;
			}
			if (flag) break;
		}

		// 채워진게 없으면 끝에다가 채움
		if (!flag) {
			for (int y = 0; y < 4; y++) {
				if (CheckY[y] == 0) continue;
				blue[y][5] = 1;
			}
		}
	}

	// 밀기전에 폭탄부터 터트리자
	BombBlue();
	
	// 연한블록에 블록이들어있으면 들어있는 만큼 밀어야한다.
	int PushCnt = 0;
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 4; y++) {
			if (blue[y][x] != 0) {
				PushCnt++;
				break;
			}
		}
	}

	if (PushCnt > 0) {
		PushBlue(PushCnt);
	}

}

void PushGreen(int how) {
	int Temp[6][4] = { 0 };
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 6 - how; y++) {
			Temp[y + how][x] = green[y][x];
		}
	}
	memcpy(green, Temp, sizeof(green));
}

void RtoG(int t) {
	if (t == 1) { //1개짜리
		int idx = 0;
		for (int x = 0; x < 4; x++) {
			if (CheckX[x] == 1) idx = x;
		}

		int flag = 0;
		for (int y = 1; y < 6; y++) {
			if (green[y][idx] != 0) {
				green[y-1][idx] = 1;
				flag = 1;
				break;
			}
		}

		if (!flag) {
			green[5][idx] = 1;
		}
	}
	else if (t == 2) { // 가로2줄짜리
		
		int flag = 0; // 채우는지 안채우는지 판별
		for (int y = 1; y < 6; y++) {
			for (int x = 0; x < 4; x++) {
				if (CheckX[x] == 0) continue;
				if (green[y][x] == 0) continue;
				for (int xx = 0; xx < 4; xx++) {
					if (CheckX[xx] == 0) continue;
					green[y-1][xx] = 1;
					flag = 1;
				}
				break;
			}
			if (flag) break;
		}

		// 채워진게 없으면 끝에다가 채움
		if (!flag) {
			for (int x = 0; x < 4;x++) {
				if (CheckX[x] == 0) continue;
				green[5][x] = 1;
			}
		}
	}
	else if (t == 3) { // 세로2줄짜리
		int idx = 0;
		for (int x = 0; x < 4; x++) {
			if (CheckX[x] == 2) idx = x;
		}

		if (green[0][idx] == 0 && green[1][idx] != 0) PushGreen(1);
		else if (green[0][idx] != 0 || green[1][idx] != 0) PushGreen(2);

		int flag = 0;
		for (int y = 2; y < 6; y++) {
			if (green[y][idx] != 0) {
				green[y - 2][idx] = 1;
				green[y - 1][idx] = 1;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			green[5][idx] = 1;
			green[4][idx] = 1;
		}
	}

	BombGreen();

	// 연한블록에 블록이들어있으면 들어있는 만큼 밀어야한다.
	int PushCnt = 0;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 4; x++) {
			if (green[y][x] != 0) {
				PushCnt++;
				break;
			}
		}
	}

	if (PushCnt > 0) {
		PushGreen(PushCnt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t, r, c;
		cin >> t >> r >> c;
		memset(red, 0, sizeof(red));
		memset(CheckY, 0, sizeof(CheckY));
		memset(CheckX, 0, sizeof(CheckX));
		CheckY[r] += 1; CheckX[c] += 1;
		if (t == 1) {
			red[r][c] += 1;
		}
		else if (t == 2) {
			red[r][c] = 1;
			red[r][c + 1] = 1;
			CheckX[c+1] += 1;
			CheckY[r] += 1;

		}
		else {
			red[r][c] = 1;
			red[r + 1][c] = 1;
			CheckY[r+1] += 1;
			CheckX[c] += 1;

		}
		RtoB(t);
		RtoG(t);
	}

	int count = 0;
	for (int y = 2; y < 6; y++) {
		for (int x = 0; x < 4; x++) {
			if (green[y][x] != 0) count++;
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 2; x < 6; x++) {
			if (blue[y][x] != 0) count++;
		}
	}

	cout << score << endl << count;

	return 0;
}